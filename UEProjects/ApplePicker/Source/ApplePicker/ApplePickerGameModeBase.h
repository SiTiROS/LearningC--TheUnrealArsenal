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

private:
	int32 ApplesCaught{ 0 };
	int32 ApplesLost{ 0 };

	TWeakObjectPtr<ABasketBasePawn> BasketPawn{ nullptr };
};