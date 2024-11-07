#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "TestLevelScriptActor.generated.h"

class ACube;

UCLASS()
class CPPEXPERIMENTS_API ATestLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	ATestLevelScriptActor();

	UPROPERTY(EditDefaultsOnly)
	UClass* MyCube;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> MyCube2; // по умолчанию будет none в редакторе - надо выбирать из AActor

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACube> MyCube3; // по умолчанию будет none в редакторе - надо выбирать, но из ACube

protected:
	virtual void BeginPlay() override;

};