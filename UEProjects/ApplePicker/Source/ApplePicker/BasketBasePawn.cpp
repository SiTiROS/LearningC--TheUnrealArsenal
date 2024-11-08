#include "BasketBasePawn.h"
#include "AppleBase.h"
#include "Components/PrimitiveComponent.h"

ABasketBasePawn::ABasketBasePawn()
	: BasketSpeed(700.0f), CurrentVelocity(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Paddle1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Paddle1"));

	RootComponent = Root;
	Paddle1->SetupAttachment(Root);

	// добавляем статик мэш
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/SM_Paddle.SM_Paddle'"));
	// устанавливаем статик мэш
	if (MeshAsset.Object != nullptr) Paddle1->SetStaticMesh(MeshAsset.Object);

	// Simulation Generates Hit Events
	Paddle1->SetNotifyRigidBodyCollision(true);
}

void ABasketBasePawn::BeginPlay()
{
	Super::BeginPlay();

	Paddle1->OnComponentHit.AddDynamic(this, &ABasketBasePawn::OnHit); // привязка функции к делегату
}

void ABasketBasePawn::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	AAppleBase* AppleToCatch = Cast<AAppleBase>(OtherActor);

	if (AppleToCatch)
	{
		OtherActor->Destroy();
	}
}

void ABasketBasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + CurrentVelocity * DeltaTime;
		SetActorLocation(NewLocation);
	}
}

void ABasketBasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ABasketBasePawn::MoveRight);
}

void ABasketBasePawn::MoveRight(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * BasketSpeed;
	//UE_LOG(LogTemp, Warning, TEXT("Velocity: %s"), *CurrentVelocity.ToString());
}