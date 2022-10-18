// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupCollider = CreateDefaultSubobject<USphereComponent>("Pickup Collider");
	PickupCollider->SetupAttachment(RootComponent);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	Mesh->SetupAttachment(PickupCollider);
	
	PickupCollider->InitSphereRadius(100.f);

	Mesh->CanCharacterStepUpOn = ECB_Yes;
	Mesh->SetSimulatePhysics(true);
	Mesh->SetMassOverrideInKg(NAME_Actor, 50.f);
	DefaultRelativeMeshTransform = Mesh->GetRelativeTransform();
	
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

