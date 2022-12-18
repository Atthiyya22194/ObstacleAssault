// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformer.h"

// Sets default values
AMovingPlatformer::AMovingPlatformer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatformer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovingPlatformer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector CurrentLocation = GetActorLocation();
	//CurrentLocation.X = CurrentLocation.X + 100;
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
}

