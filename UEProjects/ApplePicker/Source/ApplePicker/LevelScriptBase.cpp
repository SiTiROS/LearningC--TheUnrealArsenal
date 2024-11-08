#include "LevelScriptBase.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

ALevelScriptBase::ALevelScriptBase()
	: PlayerCamera(nullptr), PlayerController(nullptr)
{
}

void ALevelScriptBase::BeginPlay()
{
	Super::BeginPlay();

	//PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		PlayerController->SetViewTarget(PlayerCamera);
	}
}