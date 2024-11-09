#include "ApplePickerGameModeBase.h"
#include "AppleBase.h"
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
		//  Stop Spawning Apples
		TArray<AActor*> FoundTrees;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATreeBase::StaticClass(), FoundTrees);

		for (auto FoundTree : FoundTrees)
		{
			// FoundTree->Destroy();

			ATreeBase* TreeTemp = Cast<ATreeBase>(FoundTree);
			TreeTemp->StopSpawningApple();
		}

		// Destroy Remaining Apples
		TArray<AActor*> FoundApples;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAppleBase::StaticClass(), FoundApples);

		for (auto FoundApple : FoundApples)
		{
			FoundApple->Destroy();
		}
	}
}