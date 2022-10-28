// Copyright Epic Games, Inc. All Rights Reserved.

#include "ClobberPartyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Item.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AClobberPartyCharacter::AClobberPartyCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(50.f, 95.f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// TODO: Move off of third-person cam to static camera.

	// Configure character movement.
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 720.0f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Set movement physics.
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	MovementComponent->GravityScale = GravityScale;
	MovementComponent->JumpZVelocity = JumpZVelocity;
	MovementComponent->AirControl = AirControl;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AClobberPartyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AClobberPartyCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void AClobberPartyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AClobberPartyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AClobberPartyCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Interact"), EInputEvent::IE_Pressed, this, &AClobberPartyCharacter::Interact);
}

void AClobberPartyCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(FVector::UnitX() * AxisValue);
}

void AClobberPartyCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(FVector::UnitY() * AxisValue);
}

void AClobberPartyCharacter::Interact()
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors, AItem::StaticClass());
	if (!Actors.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapping, %s"), *Actors[0]->GetName());
	}
}

void AClobberPartyCharacter::PickUp(AItem Item)
{
    if (Item.bGoesInRightHand)
    {
        // Detach from right hand.
		// Place current item in right hand.
    } else
    {
        // Do same with left hand.
    }
}
