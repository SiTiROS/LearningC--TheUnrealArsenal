#include "AppleBase.h"

AAppleBase::AAppleBase()
{
	PrimaryActorTick.bCanEverTick = true;

	AppleMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AppleMeshComponent"));
	RootComponent = AppleMeshComponent;

	// добавляем статик мэш
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/SM_Apple.SM_Apple'"));

	if (MeshAsset.Object != nullptr)
	{
		// устанавливаем статик мэш
		AppleMeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	AppleMeshComponent->SetSimulatePhysics(true);
	AppleMeshComponent->SetRelativeScale3D(FVector(0.45f));
}

void AAppleBase::BeginPlay()
{
	Super::BeginPlay();

}

void AAppleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}