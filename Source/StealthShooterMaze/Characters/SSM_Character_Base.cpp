// Fill out your copyright notice in the Description page of Project Settings.


#include "SSM_Character_Base.h"

#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASSM_Character_Base::ASSM_Character_Base()
{
	// Set this character to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.0f, 0.f); // ...at this rotation rate
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	// Create spring arm
	springArm = CreateDefaultSubobject<USpringArmComponent>(FName("Spring Arm"));
	springArm->SetupAttachment(RootComponent);
	springArm->SetUsingAbsoluteRotation(true);
	springArm->bDoCollisionTest = true;
	springArm->bUsePawnControlRotation = true;

	// Create camera component
	camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));
	camera->SetupAttachment(springArm);
	camera->bUsePawnControlRotation = true;

	// Set tag
	Tags.Add(FName(TEXT("Player")));
}

// Called when the game starts or when spawned
void ASSM_Character_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASSM_Character_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}