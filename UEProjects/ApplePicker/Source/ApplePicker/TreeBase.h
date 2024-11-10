#pragma once

#include "AppleTreeElementBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreeBase.generated.h"

class AAppleBase;
class USphereComponent;

UCLASS()
class APPLEPICKER_API ATreeBase : public AAppleTreeElementBase
{
	GENERATED_BODY()

public:
	ATreeBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* TreeMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float MovementSpeed;

	/**
	* Left and right boundaries
	* 
	* When reached the Tree Actor movies in opposite direction
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float OuterBoundary;

	/**
	* Left and inner boundaries
	* 
	* Tree randomly redirects only if it within the inner boundary
	* 
	* Smooths the redirection at the boundary
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float InnerBoundary;

	/**
	* Called to move opposite direction
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float ChanceToRedirect;

	/**
	* Time to change directions
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float RedirectTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float SecondsBetweenAppleDrops;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setup")
	TSubclassOf<AAppleBase> SpawnApple;

public:
	virtual void Tick(float DeltaTime) override;

	void StartSpawningApples();
	void StartRedirecting();
	void StopSpawningApples();
	void StopRedirecting();
	void SetShouldMove(const bool bInShouldMove);

private:
	FTimerHandle ChangeDirectionTimer;
	FTimerHandle AppleSpawnTimer;

	void ChangeDirection();
	void AppleSpawn() const;

	bool bShouldMove;
};