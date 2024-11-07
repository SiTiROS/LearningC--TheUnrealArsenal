#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreeBase.generated.h"

class USphereComponent;

UCLASS()
class APPLEPICKER_API ATreeBase : public AActor
{
	GENERATED_BODY()

public:
	ATreeBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* TreeMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereCollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float MovementSpeed;

	/**
	* Left and right boundaries
	* when reached the Tree Actor movies in opposite direction
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float Boundary;

	/**
	* Called to move opposite direction
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float ChanceToRedirect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float RedirectTime;

public:
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle ChangeDirectionTimer;

	void ChangeDirection();
};