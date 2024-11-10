#include "AppleBase.h"
#include "ApplePickerGameModeBase.h"
#include "Kismet/GameplayStatics.h"

AAppleBase::AAppleBase()
	: FloorBoundary(-680.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	AppleMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AppleMeshComponent"));
	RootComponent = AppleMeshComponent;

	// Добавляем статик мэш
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/SM_Apple.SM_Apple'"));

	// Устанавливаем статик мэш
	if (MeshAsset.Object != nullptr) AppleMeshComponent->SetStaticMesh(MeshAsset.Object);

	AppleMeshComponent->SetSimulatePhysics(true);
	AppleMeshComponent->SetRelativeScale3D(FVector(0.45f));
}

void AAppleBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentGameMode = Cast<AApplePickerGameModeBase>(UGameplayStatics::GetGameMode(this));
}

void AAppleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If the apple falls on the floor
	if (GetActorLocation().Z <= FloorBoundary)
	{
		Destroy();

		if (CurrentGameMode.IsValid())
		{
			CurrentGameMode->HandleAppleLost();
		}
	}
}