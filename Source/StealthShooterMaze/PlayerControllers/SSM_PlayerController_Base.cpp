// Fill out your copyright notice in the Description page of Project Settings.


#include "SSM_PlayerController_Base.h"
#include "../Characters/SSM_Character_Base.h"

#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ASSM_PlayerController_Base::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(inputGameOnly);
	SetShowMouseCursor(false);

	// Adding input mapping context
	if (UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subSystem->AddMappingContext(mappingContext, 0);
	}

	character = Cast<ASSM_Character_Base>(GetPawn());
}

void ASSM_PlayerController_Base::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* enhincedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Bind movement
		enhincedInput->BindAction(actionMovement, ETriggerEvent::Triggered, this, &ASSM_PlayerController_Base::CharacterMovement);
		// Bind character look
		enhincedInput->BindAction(actionMouseRotation, ETriggerEvent::Triggered, this, &ASSM_PlayerController_Base::CharacterLook);
	}
}

void ASSM_PlayerController_Base::CharacterMovement(const FInputActionValue& value)
{
	FVector2D moveVector = value.Get<FVector2D>();

	if (IsValid(character))
	{
		// find out which way is forward
		FRotator rotationYaw = FRotator(0.f, GetControlRotation().Yaw, 0.f);

		// get forward vector
		const FVector forwardDirection = FRotationMatrix(rotationYaw).GetUnitAxis(EAxis::X);
		// get right vector
		const FVector rightDirection = FRotationMatrix(rotationYaw).GetUnitAxis(EAxis::Y);
		// add movement
		character->AddMovementInput(forwardDirection, moveVector.Y);
		character->AddMovementInput(rightDirection, moveVector.X);
	}
}

void ASSM_PlayerController_Base::CharacterLook(const FInputActionValue& value)
{
	FVector2D lookVector = value.Get<FVector2D>();

	if (IsValid(character))
	{
		AddYawInput(lookVector.X);
		AddPitchInput(lookVector.Y);
	}
}
