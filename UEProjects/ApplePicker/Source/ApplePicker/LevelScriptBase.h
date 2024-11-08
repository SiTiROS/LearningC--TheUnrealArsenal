#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScriptBase.generated.h"

class ACameraActor;
class APlayerController;

UCLASS()
class APPLEPICKER_API ALevelScriptBase : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	ALevelScriptBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Setup")
	ACameraActor* PlayerCamera;

private:
	APlayerController* PlayerController;
};