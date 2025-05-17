// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "Preferences/PersonaOptions.h"


ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	auto Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftDoor"));
	LeftDoor->SetupAttachment(Root);

	RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightDoor"));
	RightDoor->SetupAttachment(Root);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();

	if (LeftDoor && RightDoor)
	{
		LeftStartPos = LeftDoor->GetRelativeLocation();
		RightStartPos = RightDoor->GetRelativeLocation();

		LeftTargetPos = LeftStartPos + FVector(-140, 0, 0);
		RightTargetPos = RightStartPos + FVector(140, 0, 0); 
	}
}

void ADoor::OpenDoor_Implementation()
{
	if (LeftDoor && RightDoor)
	{
		bIsOpening = !bIsOpening;
		ElapsedTime = 0.0f;
		GetWorld()->GetTimerManager().SetTimer(
			DoorMoveTimerHandle,
			this,
			&ADoor::MoveDoors,
			0.01f,
			true);

		if (bIsOpening)
		{
			GetWorld()->GetTimerManager().SetTimer(
				DoorCloseTimerHandle,
				this,
				&ADoor::OpenDoor_Implementation,
				4.0f,
				false);			
		}
	}
}

void ADoor::MoveDoors()
{
	ElapsedTime += 0.01f;
	float Alpha = FMath::Clamp(ElapsedTime / 1.0f, 0.0f, 1.0f);

	FVector NewLeft, NewRight;
	
	NewLeft = FMath::Lerp(
		bIsOpening ? LeftStartPos : LeftTargetPos,
		bIsOpening ? LeftTargetPos : LeftStartPos,
		Alpha);
	NewRight = FMath::Lerp(
	bIsOpening ? RightStartPos : RightTargetPos,
	bIsOpening ? RightTargetPos : RightStartPos,
		Alpha);


	LeftDoor->SetRelativeLocation(NewLeft);
	RightDoor->SetRelativeLocation(NewRight);

	if (Alpha >= 1.0f)
	{
		GetWorld()->GetTimerManager().ClearTimer(DoorMoveTimerHandle);
	}
}