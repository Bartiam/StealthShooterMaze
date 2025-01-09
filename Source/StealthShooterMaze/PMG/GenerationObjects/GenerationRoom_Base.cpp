// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerationRoom_Base.h"

// Sets default values
AGenerationRoom_Base::AGenerationRoom_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	floorMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Floor")));
	SetRootComponent(floorMesh);
}

// Called when the game starts or when spawned
void AGenerationRoom_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenerationRoom_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

