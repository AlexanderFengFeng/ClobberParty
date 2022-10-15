// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ClobberPartyPlayerController.generated.h"

class ALevelCamera;

UCLASS()
class AClobberPartyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AClobberPartyPlayerController();


protected:
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;

private:
	ALevelCamera* LevelCamera;
	void AssignLevelCamera();
};


