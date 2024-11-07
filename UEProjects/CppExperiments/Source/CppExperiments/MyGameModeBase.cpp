#include "MyGameModeBase.h"
#include "Cube.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FTransform DemoTransform{FRotator(0.0f, 90.0f, 0.0f), FVector(50.0f), FVector(1.0f)};
	UE_LOG(LogTemp, Error, TEXT("DemoTransform(l, r, s): %s"), *DemoTransform.ToString());

	GetWorldTimerManager().SetTimer(SpawnTimer, this, &AMyGameModeBase::SpawnCube, 2.0f, true, 0.0f);
}

void AMyGameModeBase::SpawnCube()
{
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(FVector(0, 0, 500));
	SpawnTransform.SetScale3D(FVector(2, 2, 2));
	SpawnTransform.SetRotation(FRotator(22.0f, 1.0f, 55.0f).Quaternion());

	if (UWorld* World = GetWorld())
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawned Cube, Location: %s, Rotation: %s, Scale: %s"),
			*SpawnTransform.GetLocation().ToString(),
			*SpawnTransform.GetRotation().ToString(),
			*SpawnTransform.GetScale3D().ToString());

		ACube* NewCube = World->SpawnActor<ACube>(Cube, SpawnTransform);
		SpawnedCubes.Add(NewCube);

		FTimerHandle NewDestroyTimer;
		World->GetTimerManager().SetTimer(NewDestroyTimer, TFunction<void()>([this, NewCube]()
		{
			this->InvokeDestroy(NewCube);
		}), 5.0f, false);
	}
}

void AMyGameModeBase::InvokeDestroy(ACube* NewCube)
{
	NewCube->Destroy();
}