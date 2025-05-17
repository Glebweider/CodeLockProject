// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestedProject/Core/Player/Interfaces/InputToPlayer/InputToPlayerInterface.h"
#include "APlayerCharacter.generated.h"

UCLASS()
class TESTEDPROJECT_API AAPlayerCharacter : public ACharacter, public IInputToPlayerInterface
{
	GENERATED_BODY()

public:
	AAPlayerCharacter();

	/** Interfaces PlayerInput */
	virtual void HandleInteract_Implementation() override;

protected:
	virtual void BeginPlay() override;

	/** Assets */
	UPROPERTY(BlueprintReadWrite, Category = "Player")
	APlayerController* BP_PlayerController;
};
