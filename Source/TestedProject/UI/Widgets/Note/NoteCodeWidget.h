// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "NoteCodeWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTEDPROJECT_API UNoteCodeWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void HandleExit();
	
	/** Binds */
	UPROPERTY(meta=(BindWidget))
	UButton* Button_Exit;
};
