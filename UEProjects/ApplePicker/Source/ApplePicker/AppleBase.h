#pragma once

#include "AppleTreeElementBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleBase.generated.h"

class AApplePickerGameModeBase;

UCLASS()
class APPLEPICKER_API AAppleBase : public AAppleTreeElementBase
{
	GENERATED_BODY()

public:
	AAppleBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AppleMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float FloorBoundary;

public:
	virtual void Tick(float DeltaTime) override;

private:
	TWeakObjectPtr<AApplePickerGameModeBase> CurrentGameMode{ nullptr };
};