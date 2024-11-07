#include "PropertyLogComponent.h"


UPropertyLogComponent::UPropertyLogComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

	Owner = GetOwner();
}

void UPropertyLogComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Error, TEXT("Owner: %s"), *Owner->GetName()); // имя актора 
	
	// другой способ
	AActor* OwnerActor = GetOwner();
	FString OwnerName = OwnerActor->GetActorNameOrLabel(); // название актора в редакторе в ворлд оутлайнере
	UE_LOG(LogTemp, Error, TEXT("Owner: %s"), *OwnerName);
	
	
}

void UPropertyLogComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}