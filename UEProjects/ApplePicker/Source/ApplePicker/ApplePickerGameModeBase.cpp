#include "ApplePickerGameModeBase.h"
#include "AppleBase.h"
#include "AppleTreeElementBase.h"
#include "BasketBasePawn.h"
#include "TreeBase.h"
#include "Kismet/GameplayStatics.h"

void AApplePickerGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	BasketPawn = Cast<ABasketBasePawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	// Deactivate player input
	if (BasketPawn.IsValid())
	{
		BasketPawn->DisableInput(nullptr);
	}

	FTimerHandle GameStartCountdownTimer;
	GetWorld()->GetTimerManager().SetTimer(GameStartCountdownTimer, this, &AApplePickerGameModeBase::HandleGameStart, GameStartDelay, false);
}

void AApplePickerGameModeBase::HandleAppleCaught()
{
	ApplesCaught += 1;

	UE_LOG(LogTemp, Warning, TEXT("Apple Caught!"));
	UE_LOG(LogTemp, Warning, TEXT("Total Apple Caught: %d"), ApplesCaught);

	if (ApplesCaught >= ApplesToCatch)
	{
		// We win the game
		HandleGameOver(true); // в BP на это ещё подвязана логика
	}
}

void AApplePickerGameModeBase::HandleAppleLost()
{
	ApplesLost += 1;

	UE_LOG(LogTemp, Warning, TEXT("Apple Lost!"));
	UE_LOG(LogTemp, Warning, TEXT("Total Apple Lost: %d"), ApplesLost);

	if (BasketPawn.IsValid())
	{
		BasketPawn->HandlePaddleDestruction();
	}

	if (ApplesLost >= ApplesToLose)
	{
		// We lose the game
		HandleGameOver(false); // в BP на это ещё подвязана логика
	}
}

void AApplePickerGameModeBase::HandleGameOver_Implementation(bool IsWinner)
{
	if (const UWorld* World = GetWorld())
	{
		// Finish the game
		TArray<AActor*> FoundAppleTreeElements;
		UGameplayStatics::GetAllActorsOfClass(World, AAppleTreeElementBase::StaticClass(), FoundAppleTreeElements);

		for (const auto FoundTreeElement : FoundAppleTreeElements)
		{
			if (ATreeBase* TreeTemp = Cast<ATreeBase>(FoundTreeElement))
			{
				// Stop Spawning Apples
				TreeTemp->StopSpawningApples();
				TreeTemp->StopRedirecting();
				TreeTemp->SetShouldMove(false);
				// TreeTemp->Destroy();
			}
			else if (AAppleBase* AppleTemp = Cast<AAppleBase>(FoundTreeElement))
			{
				// Destroy Remaining Apples
				AppleTemp->Destroy();
			}
		}

		if (BasketPawn.IsValid() && BasketPawn->GetBasketPlayerController())
		{
			BasketPawn->DisableInput(BasketPawn->GetBasketPlayerController());
			BasketPawn->SetActorTickEnabled(false);
			// BasketPawn->SetActorHiddenInGame(true);
		}
	}
}

void AApplePickerGameModeBase::HandleGameStart() const
{
	if (const UWorld* World = GetWorld())
	{
		TArray<AActor*> FoundTreeElements;
		UGameplayStatics::GetAllActorsOfClass(World, AAppleTreeElementBase::StaticClass(), FoundTreeElements);

		for (const auto FoundTreeElement : FoundTreeElements)
		{
			if (ATreeBase* TreeTemp = Cast<ATreeBase>(FoundTreeElement))
			{
				// Start tree
				TreeTemp->StartSpawningApples();
				TreeTemp->StartRedirecting();
				TreeTemp->SetShouldMove(true);
			}
		}

		// Activate player input
		if (BasketPawn.IsValid() && BasketPawn->GetBasketPlayerController())
		{
			BasketPawn->EnableInput(BasketPawn->GetBasketPlayerController());
		}
	}
}