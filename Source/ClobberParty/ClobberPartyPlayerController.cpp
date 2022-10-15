// Copyright Epic Games, Inc. All Rights Reserved.

#include "ClobberPartyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "LevelCamera.h"


AClobberPartyPlayerController::AClobberPartyPlayerController()
{

}

void AClobberPartyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    AssignLevelCamera();
    SetViewTarget(LevelCamera);
}

void AClobberPartyPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void AClobberPartyPlayerController::AssignLevelCamera()
{
    TArray<AActor*> Actors;
    UGameplayStatics::GetAllActorsOfClass(this, ALevelCamera::StaticClass(), Actors);
    if (Actors.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("%s must have a level camera."), *GetName());
        return;
    }
    else if (Actors.Num() > 1)
    {
        UE_LOG(LogTemp, Error, TEXT("%s has more than one camera."), *GetName());
    }
    LevelCamera = Cast<ALevelCamera>(Actors[0]);
}
    