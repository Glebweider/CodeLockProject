// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "TestedProject/Core/Builds/CodeLock/CodeLock.h"
#include "TestedProject/UI/Widgets/NumberButton/NumberButtonWidget.h"
#include "CodeLockWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTEDPROJECT_API UCodeLockWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	/** Assets */
	UPROPERTY()
	ACodeLock* CodeLockOwner;
	
protected:
	/** Binds */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_Password;

	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* GridPanel_Numbers;

	UPROPERTY(meta = (BindWidget))
	UButton* EnterTextArrow;

	UPROPERTY(meta = (BindWidget))
	UButton* RemoveTextArrow;

	UPROPERTY(meta=(BindWidget))
	UButton* Button_Exit;

	/**Sounds */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* ClickSound;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UUserWidget> NumberButtonClass;
	
	UFUNCTION()
	void HandleNumberClicked(int32 Number);

	UFUNCTION()
	void HandleEnter();

	UFUNCTION()
	void HandleExit();

	UFUNCTION()
	void HandleRemove();

	UFUNCTION()
	void UpdateTextPassword();
	
	FString InputCode;
};
