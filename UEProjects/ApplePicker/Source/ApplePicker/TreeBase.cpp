#include "TreeBase.h"
#include "Components/SphereComponent.h"
#include "ApplePicker/AppleBase.h"

ATreeBase::ATreeBase()
	: MovementSpeed(550.0f),
	  Boundary(850.0f),
	  ChanceToRedirect(0.4f),
	  RedirectTime(1.0f),
	  SecondsBetweenAppleDrops(1.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	TreeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TreeMeshComponent"));
	RootComponent = TreeMeshComponent;

	SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollisionComponent"));
	SphereCollisionComponent->SetupAttachment(RootComponent);

	// добавляем статик мэш
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/SM_Tree.SM_Tree'"));
	// устанавливаем статик мэш
	if (MeshAsset.Object != nullptr) TreeMeshComponent->SetStaticMesh(MeshAsset.Object);
}

void ATreeBase::BeginPlay()
{
	Super::BeginPlay();

	// проверка на установленный класс
	if (SpawnApple == nullptr)
	{
		SpawnApple = AAppleBase::StaticClass();
		// UE_LOG(LogTemp, Error, TEXT("MyApple == nullptr"));
	}

	GetWorld()->GetTimerManager().SetTimer(ChangeDirectionTimer, this, &ATreeBase::ChangeDirection, RedirectTime, true, 2.5f);
	GetWorld()->GetTimerManager().SetTimer(AppleSpawnTimer, this, &ATreeBase::AppleSpawn, SecondsBetweenAppleDrops, true, 2.0f);
}

void ATreeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector TempLocation{ GetActorLocation() };
	// UE_LOG(LogTemp, Display, TEXT("TempLocation: %f"), TempLocation.Y);

	// Check is Apple Tree within bounds
	if (TempLocation.Y <= -Boundary)
	{
		// Move Right
		MovementSpeed = FMath::Abs(MovementSpeed);
		// UE_LOG(LogTemp, Warning, TEXT("Change Right, %f"), TempLocation.Y);
	}
	else if (TempLocation.Y >= Boundary)
	{
		// Move Left
		MovementSpeed = -(FMath::Abs(MovementSpeed));
		// UE_LOG(LogTemp, Warning, TEXT("Change Left, %f"), TempLocation.Y);
	}

	// Add offset and set new location
	TempLocation += FVector(0.0f, MovementSpeed * DeltaTime, 0.0f); // TempLocation.Y += MovementSpeed * DeltaTime;
	SetActorLocation(TempLocation);
}

void ATreeBase::ChangeDirection()
{
	// restriction of boundary values
	FVector TempLocation{ GetActorLocation() };
	if (TempLocation.Y <= -(Boundary - 300) || TempLocation.Y >= (Boundary - 300)) return;

	if (FMath::FRand() <= ChanceToRedirect)
	{
		// change direction
		MovementSpeed *= -1;
		// UE_LOG(LogTemp, Warning, TEXT("Random Change, %f"), TempLocation.Y);
	}
}

void ATreeBase::AppleSpawn() const
{
	// Get TreeBase current location and rotation
	FVector SpawnLocation{ GetActorLocation() };
	FRotator SpawnRotation{ GetActorRotation() };

	// Add offset randomly to the left or to the right of the current location
	SpawnLocation.Y += (FMath::FRand() <= 0.5f) ? 150.0f : -150.0f;

	// Spawn apple at new offset location
	if (UWorld* World = GetWorld())
	{
		World->SpawnActor<AAppleBase>(SpawnApple, SpawnLocation, SpawnRotation);
	}
}