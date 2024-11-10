#include "TreeBase.h"
#include "ApplePicker/AppleBase.h"

ATreeBase::ATreeBase()
	: MovementSpeed(550.0f),
	  OuterBoundary(900.0f),
	  InnerBoundary(500.0f),
	  ChanceToRedirect(0.4f),
	  RedirectTime(1.0f),
	  SecondsBetweenAppleDrops(1.0f),
	  bShouldMove(false)
{
	PrimaryActorTick.bCanEverTick = true;

	TreeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TreeMeshComponent"));
	RootComponent = TreeMeshComponent;

	// Добавляем статик мэш
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/SM_Tree.SM_Tree'"));
	// Устанавливаем статик мэш
	if (MeshAsset.Object != nullptr) TreeMeshComponent->SetStaticMesh(MeshAsset.Object);
}

void ATreeBase::BeginPlay()
{
	Super::BeginPlay();

	// Проверка на установленный класс
	if (SpawnApple == nullptr)
	{
		SpawnApple = AAppleBase::StaticClass();
	}
}

void ATreeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldMove)
	{
		FVector TempLocation{ GetActorLocation() };

		// Check is Apple Tree within bounds
		if (TempLocation.Y <= -OuterBoundary)
		{
			// Move Right
			MovementSpeed = FMath::Abs(MovementSpeed);
		}
		else if (TempLocation.Y >= OuterBoundary)
		{
			// Move Left
			MovementSpeed = -(FMath::Abs(MovementSpeed));
		}

		// Add offset and set new location
		TempLocation.Y += MovementSpeed * DeltaTime;
		SetActorLocation(TempLocation);
	}
}

void ATreeBase::ChangeDirection()
{
	if (bShouldMove)
	{
		FVector TempLocation{ GetActorLocation() };

		// Only redirect if within InnerBoundary
		if (TempLocation.Y <= InnerBoundary && TempLocation.Y >= -InnerBoundary)
		{
			if (FMath::FRand() <= ChanceToRedirect)
			{
				// Change direction
				MovementSpeed *= -1.0f;
			}
		}
	}
}

void ATreeBase::AppleSpawn() const
{
	// Get TreeBase current location and rotation
	FVector SpawnLocation{ GetActorLocation() };
	const FRotator SpawnRotation{ GetActorRotation() };

	// Add offset randomly to the left or to the right of the current location
	SpawnLocation.Y += (FMath::FRand() <= 0.5f) ? 150.0f : -150.0f;

	// Spawn apple at new offset location
	if (UWorld* World = GetWorld())
	{
		World->SpawnActor<AAppleBase>(SpawnApple, SpawnLocation, SpawnRotation);
	}
}

void ATreeBase::StartSpawningApples()
{
	GetWorld()->GetTimerManager().SetTimer(AppleSpawnTimer, this, &ATreeBase::AppleSpawn, SecondsBetweenAppleDrops, true, 2.0f);
}

void ATreeBase::StartRedirecting()
{
	GetWorld()->GetTimerManager().SetTimer(ChangeDirectionTimer, this, &ATreeBase::ChangeDirection, RedirectTime, true);
}

void ATreeBase::StopSpawningApples()
{
	GetWorld()->GetTimerManager().ClearTimer(AppleSpawnTimer);
}

void ATreeBase::StopRedirecting()
{
	GetWorld()->GetTimerManager().ClearTimer(ChangeDirectionTimer);
}

void ATreeBase::SetShouldMove(const bool bInShouldMove)
{
	bShouldMove = bInShouldMove;
}