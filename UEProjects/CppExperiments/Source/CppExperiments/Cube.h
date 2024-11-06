#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cube.generated.h"

UENUM(BlueprintType)
enum class ChangeImpulseMethod : uint8
{
	AddImpulse UMETA(DisplayName = "AddImpulse"),
	AddForce UMETA(DisplayName = "AddForce")
};

UCLASS()
class CPPEXPERIMENTS_API ACube : public AActor
{
	GENERATED_BODY()
	
public:	
	ACube();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditAnywhere, Category = "Settings")
	bool bIsActivateImpulse;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (EditCondition = "bIsActivateImpulse"))
	ChangeImpulseMethod EChangeImpulseMethod;
	
	UPROPERTY(EditAnywhere, Category = "Settings", meta = (EditCondition = "bIsActivateImpulse"))
	float ImpulseVelocity;
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};