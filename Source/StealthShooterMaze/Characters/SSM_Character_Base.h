// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../FunctionLibs/SSM_Types_Base.h"


#include "SSM_Character_Base.generated.h"

UCLASS()
class STEALTHSHOOTERMAZE_API ASSM_Character_Base : public ACharacter
{
	GENERATED_BODY()

public:
	ASSM_Character_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: // Private variables

	

public: // Getters and setters

public: // Public variables

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Specifications")
	FCharacterSpecification characterSpeedSettings;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* camera = nullptr;

	UPROPERTY(EditDefaultsOnly)
	class USpringArmComponent* springArm = nullptr;

public: // Public functions

};
