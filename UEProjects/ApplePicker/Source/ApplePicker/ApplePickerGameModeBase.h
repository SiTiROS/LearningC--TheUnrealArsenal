#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ApplePickerGameModeBase.generated.h"

class ABasketBasePawn;
class UApplePickerUserWidgetBase;

UCLASS()
class APPLEPICKER_API AApplePickerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleAppleCaught();

	UFUNCTION()
	void HandleAppleLost();

	UFUNCTION(BlueprintCallable)
	float GetGameStartDelay() const { return GameStartDelay; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Win")
	bool bIsGameActive{ false };

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent)
	void HandleGameOver(bool IsWinner);

	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 ApplesToCatch{ 10 };

	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 ApplesToLose{ 3 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float GameStartDelay{ 5.0f };

	// To specify widget blueprint/type in Editor
	UPROPERTY(EditAnywhere, Category = "Setup|Widgets")
	TSubclassOf<UUserWidget> GameWidgetType;

	UPROPERTY()
	UApplePickerUserWidgetBase* Widget;

private:
	int32 ApplesCaught{ 0 };
	int32 ApplesLost{ 0 };

	TWeakObjectPtr<ABasketBasePawn> BasketPawn{ nullptr };

	void HandleGameStart();

	void UpdateWidgetText() const;
};