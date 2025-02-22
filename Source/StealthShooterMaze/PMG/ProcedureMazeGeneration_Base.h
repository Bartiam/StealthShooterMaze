// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../FunctionLibs/SSM_Types_Base.h"

#include "ProcedureMazeGeneration_Base.generated.h"

class AGenerationRoom_Base;

UCLASS()
class STEALTHSHOOTERMAZE_API AProcedureMazeGeneration_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcedureMazeGeneration_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: // Private functions

public: // Public variables

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPMGSettings QuantitySettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPMGObjects ObjectSettings;
};
