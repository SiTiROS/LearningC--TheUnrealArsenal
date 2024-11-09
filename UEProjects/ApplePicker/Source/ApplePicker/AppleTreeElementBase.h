#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleTreeElementBase.generated.h"

UCLASS()
class APPLEPICKER_API AAppleTreeElementBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AAppleTreeElementBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
