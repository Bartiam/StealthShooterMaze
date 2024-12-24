// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SSM_PlayerController_Base.generated.h"

class UInputAction;

UCLASS()
class STEALTHSHOOTERMAZE_API ASSM_PlayerController_Base : public APlayerController
{
	GENERATED_BODY()
	
public: // Public variables

	// Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inputs")
	UInputAction* actionMovement = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inputs")
	UInputAction* actionJump = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inputs")
	UInputAction* actionSprint = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inputs")
	UInputAction* actionCrouch = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inputs")
	UInputAction* actionMouseRotation = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inputs")
	class UInputMappingContext* mappingContext = nullptr;
};
