#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasketBasePawn.generated.h"

UCLASS()
class APPLEPICKER_API ABasketBasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasketBasePawn();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Paddle1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float BasketSpeed;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	FVector CurrentVelocity;

	void MoveRight(float AxisValue);
};