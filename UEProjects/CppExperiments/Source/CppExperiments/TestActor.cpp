#include "TestActor.h"
#include "Components/StaticMeshComponent.h"

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Health = 100;
	Armor = 100;
	Strength = 50;
	Intelligence = 50;
	bShouldMove = false;
	bShouldRotate = false;

	RootComp = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = RootComp;
	// SetRootComponent(RootComp); //то же самое

	// StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	// StaticMesh->SetupAttachment(RootComponent);
	// StaticMesh->SetupAttachment(GetRootComponent());
	// StaticMesh->SetupAttachment(Root);
	// StaticMeshComp->AttachToComponent(RootComp, FAttachmentTransformRules::KeepRelativeTransform); // лучше не в конструкторе

	//StaticMeshComp->AddWorldRotation(FRotator(0.0f, 10.0f, 0.0f));

	ConeMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ConeStaticMesh"));
	PyramidMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PyramidStaticMesh"));
	TargetMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetStaticMesh"));

	ConeMeshComp->SetupAttachment(RootComponent);
	PyramidMeshComp->SetupAttachment(RootComponent);
	TargetMeshComp->SetupAttachment(ConeMeshComp); // Привязываем TargetMeshComp к ConeMeshComp

	TargetMeshComp->AddWorldOffset(FVector(0.0f, 150.0f, 0.0f));
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	// SetActorLocation(CurrentLocation);
	// InitialLocation = GetActorLocation();

	// Открепляем PyramidMeshComp от текущего родителя
	// PyramidMeshComp->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);


	// Произвольные правила привязки
	FAttachmentTransformRules MyTransformRules{EAttachmentRule::KeepWorld, EAttachmentRule::KeepRelative,
	                                           EAttachmentRule::KeepRelative, false};

	// Привязываем PyramidMeshComp к TargetMeshComp
	PyramidMeshComp->AttachToComponent(TargetMeshComp, MyTransformRules);

	PyramidMeshComp->AddLocalOffset(FVector(0.0f, 0.0f, 50.0f));
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rotator = FRotator(0.0f, 10.0f * DeltaTime, 0.0f);
	PyramidMeshComp->AddRelativeRotation(Rotator);

	if (bShouldMove)
	{
		AddActorLocalOffset(FVector(0.0f, 0.0f, 1.0f));
		// AddActorWorldOffset(FVector(0.0f, 0.0f, 1.0f));
		// CurrentLocation = FVector(0.0f, 0.0f, 100.0f);
	}

	if (bShouldRotate)
	{
		AddActorLocalRotation(FRotator(0.0f, 1.0f, 0.0f));
		// AddActorWorldRotation(FRotator(0.0f, 1.0f, 0.0f));
		// CurrentLocation = FVector(0.0f, 0.0f, 100.0f);
	}

}