#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ApplePickerUserWidgetBase.generated.h"

UCLASS()
class APPLEPICKER_API UApplePickerUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetApplesCollectedText(int32 ApplesCollected, int32 ApplesToCollect);

	UFUNCTION(BlueprintImplementableEvent)
	void SetGameOverText(bool bWonGame);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float GameStartDelay{ 5.0f };
};