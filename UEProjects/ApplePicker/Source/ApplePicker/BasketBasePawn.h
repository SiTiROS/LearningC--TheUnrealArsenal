#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasketBasePawn.generated.h"

class AApplePickerGameModeBase;
class UNiagaraSystem;

UCLASS()
class APPLEPICKER_API ABasketBasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasketBasePawn();

protected:
	virtual void PreRegisterAllComponents() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	TArray<UStaticMeshComponent*> Paddles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	int32 NumbersPaddles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float BasketSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	FVector PaddleOffset;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Setup|Particles Effects")
	UNiagaraSystem* PaddleDestroyedParticles;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HandlePaddleDestruction();

	APlayerController* GetBasketPlayerController() const;

private:
	FVector CurrentVelocity;

	void MoveRight(const float AxisValue);

	TWeakObjectPtr<AApplePickerGameModeBase> CurrentGameMode{ nullptr };
	TWeakObjectPtr<APlayerController> CurrentPlayerController{ nullptr };
};