// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NumberButtonWidget.generated.h"

class UTextBlock;
class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNumberClicked, int32, Number);

UCLASS()
class TESTEDPROJECT_API UNumberButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY()
	int32 Number;

	UPROPERTY(BlueprintAssignable, Category = "Number")
	FOnNumberClicked OnNumberClicked;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	virtual void OnButtonClicked();

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_Number;
};
