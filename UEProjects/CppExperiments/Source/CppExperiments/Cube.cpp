#include "Cube.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

ACube::ACube()
{
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = CubeMesh;

	ImpulseVelocity = 100000.0f;

	CubeMesh->SetSimulatePhysics(false);

	// добавляем статик мэш
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Object != nullptr)
	{
		// устанавливаем статик мэш
		CubeMesh->SetStaticMesh(MeshAsset.Object);
	}
}

void ACube::BeginPlay()
{
	Super::BeginPlay();

	if (bIsActivateImpulse)
	{
		CubeMesh->SetSimulatePhysics(true);

		if (EChangeImpulseMethod == ChangeImpulseMethod::AddImpulse)
		{
			CubeMesh->AddImpulse(FVector(ImpulseVelocity, 0.0f, 0.0f));
		}
		else if (EChangeImpulseMethod == ChangeImpulseMethod::AddForce)
		{
			CubeMesh->AddForce(FVector(ImpulseVelocity, 0.0f, 0.0f));
		}
	}

	constexpr int32 Level = 9000;
	const FString Name = TEXT("Test");

	UE_LOG(LogTemp, Warning, TEXT("Name: %s, Level: %d"), *Name, Level);
	UE_LOG(LogTemp, Log, TEXT("%s"), *Name);
	UE_LOG(LogTemp, Error, TEXT("%s"), *Name);
	UE_LOG(LogTemp, Display, TEXT("%s"), *Name);

	const FString Temp = FString::Printf(TEXT("Name: %s, Level: %d"), *Name, Level);
	UE_LOG(LogTemp, Error, TEXT("%s"), *Temp);

	SetLifeSpan(20.0f);
}

void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult Hit;

	AddActorWorldOffset(FVector(600.0f * DeltaTime, 0.0f, 0.0f), true, &Hit);

	if (Hit.bBlockingHit)
	{
		FVector Impact = Hit.Location;
		UE_LOG(LogTemp, Warning, TEXT("Hit! Location: %s"), *Impact.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Hit! X: %f, Y: %f, Z: %f"), Impact.X, Impact.Y, Impact.Z);

		// выводим дебаг сообщение на экран
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor(FColor::Red), TEXT("HIT"));
		}

		Destroy();
	}
}