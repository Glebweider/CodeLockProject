// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestedProject/Core/Builds/Interfaces/ToBuild/ToBuildInterface.h"
#include "Door.generated.h"

UCLASS()
class TESTEDPROJECT_API ADoor : public AActor, public IToBuildInterface
{
	GENERATED_BODY()

public:
	ADoor();

	virtual void OpenDoor_Implementation() override;

protected:
	virtual void BeginPlay() override;
	virtual void MoveDoors();

	UPROPERTY(EditAnywhere)
	FTimerHandle DoorMoveTimerHandle;

	UPROPERTY(EditAnywhere)
	FTimerHandle DoorCloseTimerHandle;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeftDoor;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RightDoor;

	FVector LeftStartPos;
	FVector LeftTargetPos;
	FVector RightStartPos;
	FVector RightTargetPos;

	float ElapsedTime = 0.0f;
	
	bool bIsOpening = false;
};
