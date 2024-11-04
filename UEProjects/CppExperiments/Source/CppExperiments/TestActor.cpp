#include "TestActor.h"

#include "MovieSceneTracksComponentTypes.h"
#include "Components/StaticMeshComponent.h"

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Health = 100;
	Armor = 100;
	Strength = 50;
	Intelligence = 50;

	RootComp = CreateDefaultSubobject<USceneComponent>("Root");
	// RootComponent = Root;
	SetRootComponent(RootComp); //то же самое

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	// StaticMesh->SetupAttachment(RootComponent);
	// StaticMesh->SetupAttachment(GetRootComponent());
	// StaticMesh->SetupAttachment(Root);
	StaticMeshComp->AttachToComponent(RootComp, FAttachmentTransformRules::KeepRelativeTransform);

	// CurrentLocation = FVector(0.0f, 0.0f, 100.0f);

	bShouldMove = false;
	bShouldRotate = false;

	//StaticMeshComp->AddWorldRotation(FRotator(0.0f, 10.0f, 0.0f));
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	// SetActorLocation(CurrentLocation);
	// InitialLocation = GetActorLocation();
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldMove)
	{
		AddActorLocalOffset(FVector(0.0f, 0.0f, 1.0f));
		// AddActorWorldOffset(FVector(0.0f, 0.0f, 1.0f));
	}

	if (bShouldRotate)
	{
		AddActorLocalRotation(FRotator(0.0f, 1.0f, 0.0f));
		// AddActorWorldRotation(FRotator(0.0f, 1.0f, 0.0f));
	}

}