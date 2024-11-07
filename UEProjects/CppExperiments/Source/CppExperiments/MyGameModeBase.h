#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

class ACube;

UCLASS()
class CPPEXPERIMENTS_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACube> Cube;

protected:
	virtual void BeginPlay() override;

private:
	TArray<ACube*> SpawnedCubes;
	FTimerHandle SpawnTimer;
	
	void InvokeDestroy(ACube* NewCube);
	void SpawnCube();
};