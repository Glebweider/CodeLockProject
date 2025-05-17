// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "APlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTEDPROJECT_API AAPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	/** Actions */
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* InteractAction;
	
	/** Variables */
	UPROPERTY()
	ACharacter* ControlledCharacter;

	/** Input handlers */
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Interact();
};
