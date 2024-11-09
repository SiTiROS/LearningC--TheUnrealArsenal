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
}

void AApplePickerGameModeBase::HandleAppleCaught()
{
	ApplesCaught += 1;

	UE_LOG(LogTemp, Warning, TEXT("Apple Caught!"));
	UE_LOG(LogTemp, Warning, TEXT("Total Apple Caught: %d"), ApplesCaught);
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

	if (ApplesLost >= 3)
	{
		if (const UWorld* World = GetWorld())
		{
			TArray<AActor*> FoundAppleTreeElements;
			UGameplayStatics::GetAllActorsOfClass(World, AAppleTreeElementBase::StaticClass(), FoundAppleTreeElements);

			for (const auto FoundTreeElement : FoundAppleTreeElements)
			{
				if (ATreeBase* TreeTemp = Cast<ATreeBase>(FoundTreeElement))
				{
					// Stop Spawning Apples
					TreeTemp->StopSpawningApple();
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
}