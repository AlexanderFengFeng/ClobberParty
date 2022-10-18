// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class CLOBBERPARTY_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
	class USphereComponent* PickupCollider;

	bool bGoesInRightHand;
	bool bOccupiesBothHandsWhenUsed;
	FTransform DefaultRelativeMeshTransform;  // Since we need to set rel transform to 0 when picked up.

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
