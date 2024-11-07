#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PropertyLogComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CPPEXPERIMENTS_API UPropertyLogComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPropertyLogComponent();

	AActor* Owner;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};