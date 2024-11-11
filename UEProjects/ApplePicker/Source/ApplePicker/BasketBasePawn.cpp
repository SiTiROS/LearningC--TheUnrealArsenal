#include "BasketBasePawn.h"
#include "AppleBase.h"
#include "ApplePickerGameModeBase.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"

ABasketBasePawn::ABasketBasePawn()
	: NumbersPaddles(3),
	  BasketSpeed(700.0f),
	  PaddleOffset(0.0f, 0.0f, 100.0f),
	  CurrentVelocity(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	// Инициализация массива
	Paddles.SetNum(NumbersPaddles);

	for (int i = 0; i < NumbersPaddles; i++)
	{
		FString PaddleName = FString::Format(TEXT("Paddle_{0}"), { i });

		Paddles[i] = CreateDefaultSubobject<UStaticMeshComponent>(*PaddleName);

		if (Paddles[i] == Paddles[0])
		{
			Paddles[i]->SetupAttachment(Root);
		}
		else
		{
			Paddles[i]->SetupAttachment(Paddles[i - 1]);
		}

		// устанавливаем смещение у корзин
		Paddles[i]->SetRelativeLocation(PaddleOffset);

		// добавляем статик мэш
		ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/SM_Paddle1.SM_Paddle1'"));

		// устанавливаем статик мэш
		if (MeshAsset.Object != nullptr) Paddles[i]->SetStaticMesh(MeshAsset.Object);

		// Simulation Generates Hit Events
		Paddles[i]->SetNotifyRigidBodyCollision(true);
	}

	// вселяем игрока в пешку
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

void ABasketBasePawn::PreRegisterAllComponents()
{
	Super::PreRegisterAllComponents();

	for (int i = 0; i < NumbersPaddles; i++)
	{
		// устанавливаем смещение у корзин, чтобы была возможность менять в редакторе
		Paddles[i]->SetRelativeLocation(PaddleOffset);

		// TODO: крашится, если добавить NumbersPaddles = больше 3
	}
}

void ABasketBasePawn::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// UE_LOG(LogTemp, Display, TEXT("Transform: %s"), *Transform.GetTranslation().ToString());

	for (int i = 0; i < NumbersPaddles; i++)
	{
		// устанавливаем смещение у корзин, чтобы была возможность менять в редакторе
		// Paddles[i]->SetRelativeLocation(PaddleOffset * i);
	}
}

void ABasketBasePawn::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < NumbersPaddles; i++)
	{
		// привязка функции к делегату
		Paddles[i]->OnComponentHit.AddDynamic(this, &ABasketBasePawn::OnHit);
	}

	CurrentGameMode = Cast<AApplePickerGameModeBase>(UGameplayStatics::GetGameMode(this));

	CurrentPlayerController = Cast<APlayerController>(GetController());
}

void ABasketBasePawn::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{

	if (AAppleBase* AppleToCatch = Cast<AAppleBase>(OtherActor))
	{
		OtherActor->Destroy();

		if (CurrentGameMode.IsValid())
		{
			CurrentGameMode->HandleAppleCaught();
		}
	}
}

void ABasketBasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InputEnabled())
	{
		if (!CurrentVelocity.IsZero())
		{
			const FVector NewLocation = GetActorLocation() + CurrentVelocity * DeltaTime;

			FHitResult Hit;

			SetActorLocation(NewLocation, true, &Hit);

			// TODO: не работает хз наверное потому что root USceneComponent
			if (Hit.bBlockingHit)
			{
				FVector Impact = Hit.Location;
				UE_LOG(LogTemp, Warning, TEXT("Hit! Location: %s"), *Impact.ToString());
				UE_LOG(LogTemp, Warning, TEXT("hit:"));
			}
		}
	}
}

void ABasketBasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ABasketBasePawn::MoveRight);
}

void ABasketBasePawn::MoveRight(const float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * BasketSpeed;
}

void ABasketBasePawn::HandlePaddleDestruction()
{
	if (!Paddles.IsEmpty())
	{
		FVector TempPaddleLoc;

		if (UStaticMeshComponent* PoppedElement = Paddles.Pop())
		{
			TempPaddleLoc = PoppedElement->GetComponentLocation();
			PoppedElement->DestroyComponent();
		}

		if (PaddleDestroyedParticles != nullptr && PaddleDestroyedParticles->IsValid())
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, PaddleDestroyedParticles,
				TempPaddleLoc);
		}
	}
}

APlayerController* ABasketBasePawn::GetBasketPlayerController() const
{
	if (CurrentPlayerController.IsValid())
	{
		return CurrentPlayerController.Get();
	}

	return nullptr;
}