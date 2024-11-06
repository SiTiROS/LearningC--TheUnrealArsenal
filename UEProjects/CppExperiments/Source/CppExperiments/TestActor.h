#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class CPPEXPERIMENTS_API ATestActor : public AActor
{
	GENERATED_BODY()

public:
	ATestActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestActor|Stats")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestActor|Stats")
	int32 Armor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestActor|Stats")
	int32 Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestActor|Stats")
	int32 Intelligence;

	UPROPERTY(EditAnywhere)
	class USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* ConeMeshComp;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* PyramidMeshComp;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* TargetMeshComp;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "TestActor|Vectors")
	FVector InitialLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestActor|Vectors")
	FVector CurrentLocation;

	UPROPERTY(EditInstanceOnly, Category = "TestActor|Booleans")
	bool bShouldMove;

	UPROPERTY(EditInstanceOnly, Category = "TestActor|Booleans")
	bool bShouldRotate;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};