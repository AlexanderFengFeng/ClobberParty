// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ClobberPartyPlayerController.generated.h"


UCLASS()
class AClobberPartyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AClobberPartyPlayerController();

protected:
	virtual void PlayerTick(float DeltaTime) override;
};


