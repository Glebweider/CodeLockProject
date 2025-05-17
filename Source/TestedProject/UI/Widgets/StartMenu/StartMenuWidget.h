// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "StartMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTEDPROJECT_API UStartMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	/** Binds */
	UPROPERTY(meta = (BindWidget))
	UButton* Button_Start;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_Exit;

	/** Handles */
	UFUNCTION()
	void HandleStart();
	
	UFUNCTION()
	void HandleExit();
};
