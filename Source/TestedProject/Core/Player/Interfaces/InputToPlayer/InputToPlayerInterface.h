﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InputToPlayerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInputToPlayerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTEDPROJECT_API IInputToPlayerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interfaces")
	void HandleInteract();
};
