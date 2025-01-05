// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SSM_Types_Base.generated.h"

// State machine for movement character
UENUM(BlueprintType)
enum class EMovementState : uint8
{
	WALK UMETA(DisplayName = "Walk state"),
	SIMPLE_RUN UMETA(DisplayName = "Simple run state"),
	SPRINT UMETA(DisplayName = "Sprint state"),
	CROUCH UMETA(DisplayName = "Crouch state"),
	FAST_CROUCH UMETA(DisplayName = "Fast crouch state")
};

// A structure for storing character speed variables
USTRUCT(BlueprintType)
struct FCharacterSpeedSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float walkSpeed = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float simpleRunSpeed = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float sprintSpeed = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float crouchSpeed = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fastCrouchSpeed = 0.f;
};

UCLASS()
class STEALTHSHOOTERMAZE_API USSM_Types_Base : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};
