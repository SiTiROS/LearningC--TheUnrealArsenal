#include "TestLevelScriptActor.h"
#include "Cube.h"

ATestLevelScriptActor::ATestLevelScriptActor()
{
	// получаем указатель на класс
	MyCube = ACube::StaticClass();
}

void ATestLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	FTransform SpawnLocation;
	SpawnLocation.SetLocation(FVector(0.0f, 0.0f, 100.0f));

	UWorld* World = GetWorld();
	if (World)
	{
		// спавним объект
		World->SpawnActor<AActor>(MyCube, SpawnLocation);

		// спавним напрямую без указателя
		// GetWorld()->SpawnActor<AActor>(ACube::StaticClass(), SpawnLocation);

		World->SpawnActor<AActor>(MyCube2, FTransform(FVector(200.0f, 200.0f, 200.0f)));

		// спавним с параметрами
		ACube* SpawnedActor = World->SpawnActorDeferred<ACube>(MyCube3, FTransform(FVector(400.0f, 400.0f, 400.0f)));
		if (SpawnedActor)
		{
			// Изменяем переменную до вызова BeginPlay
			SpawnedActor->bIsActivateImpulse = true;

			// Завершаем спавн объекта, BeginPlay вызовется только после этой строки
			SpawnedActor->FinishSpawning(FTransform(FVector(400.0f, 400.0f, 400.0f)));
		}
	}
}