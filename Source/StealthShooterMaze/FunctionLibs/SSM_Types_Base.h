// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SSM_Types_Base.generated.h"


// A structure for storing character speed variables
USTRUCT(BlueprintType)
struct FCharacterSpecification
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
