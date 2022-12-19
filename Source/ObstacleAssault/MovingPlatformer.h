// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/TransformCalculus3D.h"
#include "MovingPlatformer.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatformer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatformer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	FVector StartLocation = FVector();

	UPROPERTY(EditAnywhere, Category="Moving Platform");
	FVector PlatformVelocity = FVector(100, 0, 0);
	
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveDistance = 100;
};
