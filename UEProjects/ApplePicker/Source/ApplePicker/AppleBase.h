#pragma once

#include "AppleTreeElementBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleBase.generated.h"

class AApplePickerGameModeBase;
class UNiagaraSystem;

UCLASS()
class APPLEPICKER_API AAppleBase : public AAppleTreeElementBase
{
	GENERATED_BODY()

public:
	AAppleBase();

protected:
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AppleMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Particles Effects")
	UNiagaraSystem* AppleDestroyedParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float FloorBoundary;

public:
	virtual void Tick(float DeltaTime) override;

private:
	TWeakObjectPtr<AApplePickerGameModeBase> CurrentGameMode{ nullptr };
};