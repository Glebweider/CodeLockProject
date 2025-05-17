// Fill out your copyright notice in the Description page of Project Settings.


#include "NumberButtonWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void UNumberButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Text_Number)
	{
		Text_Number->SetText(FText::AsNumber(Number));
	}

	if (Button)
	{
		Button->OnClicked.AddDynamic(this, &UNumberButtonWidget::OnButtonClicked);
	}
}

void UNumberButtonWidget::OnButtonClicked()
{
	OnNumberClicked.Broadcast(Number);
}