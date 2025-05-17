// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ToBuildInterface.generated.h"

UINTERFACE()
class UToBuildInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTEDPROJECT_API IToBuildInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interfaces")
	void OpenDoor();
};
