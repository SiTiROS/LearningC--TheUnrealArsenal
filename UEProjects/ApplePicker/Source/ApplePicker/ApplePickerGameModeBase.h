#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ApplePickerGameModeBase.generated.h"

class ABasketBasePawn;

UCLASS()
class APPLEPICKER_API AApplePickerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleAppleCaught();

	UFUNCTION()
	void HandleAppleLost();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent)
	void HandleGameOver(bool IsWinner);

	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 ApplesToCatch{ 10 };

	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 ApplesToLose{ 3 };

	UPROPERTY(EditAnywhere, Category = "Setup")
	float GameStartDelay{ 3.0f };

private:
	int32 ApplesCaught{ 0 };
	int32 ApplesLost{ 0 };

	TWeakObjectPtr<ABasketBasePawn> BasketPawn{ nullptr };

	void HandleGameStart() const;
};