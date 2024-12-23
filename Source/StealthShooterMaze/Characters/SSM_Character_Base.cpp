// Fill out your copyright notice in the Description page of Project Settings.


#include "SSM_Character_Base.h"

#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASSM_Character_Base::ASSM_Character_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.0f, 0.f);
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	
	// Configure spring arm
	springArm = CreateDefaultSubobject<USpringArmComponent>(FName(TEXT("Spring Arm")));
	springArm->SetupAttachment(RootComponent);
	springArm->bDoCollisionTest = true;
	springArm->bUsePawnControlRotation = true;
	springArm->SetUsingAbsoluteLocation(true);

	// Configure camera
	camera = CreateDefaultSubobject<UCameraComponent>(FName(TEXT("Camera")));
	camera->SetupAttachment(RootComponent);
	camera->bUsePawnControlRotation = true;

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