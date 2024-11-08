#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleBase.generated.h"

UCLASS()
class APPLEPICKER_API AAppleBase : public AActor
{
	GENERATED_BODY()

public:
	AAppleBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AppleMeshComponent;

public:
	virtual void Tick(float DeltaTime) override;
};