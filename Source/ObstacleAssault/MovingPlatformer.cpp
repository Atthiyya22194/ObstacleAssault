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
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatformer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatformer::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);		
	}
}

void AMovingPlatformer::RotatePlatform(float DT)
{
	/* Conventional Rotation Function
	 * FRotator CurrentRotation = GetActorRotation();
	 * CurrentRotation = CurrentRotation + RotationVelocity * DT;
	 * SetActorRotation(CurrentRotation);
	 */
	AddActorLocalRotation(RotationVelocity * DT);
}

bool AMovingPlatformer::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatformer::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
