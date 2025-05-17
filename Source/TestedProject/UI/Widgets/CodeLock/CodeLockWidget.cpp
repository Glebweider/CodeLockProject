// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeLockWidget.h"

#include "Kismet/GameplayStatics.h"


void UCodeLockWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!NumberButtonClass) return;

	for (int32 i = 0; i < 10; ++i)
	{
		UNumberButtonWidget* ButtonWidget = CreateWidget<UNumberButtonWidget>(this, NumberButtonClass);
		if (ButtonWidget)
		{
			ButtonWidget->Number = i;
			ButtonWidget->OnNumberClicked.AddDynamic(this, &UCodeLockWidget::HandleNumberClicked);
			
			int32 Row = (i == 9) ? 3 : i / 3;
			int32 Col = (i == 9) ? 1 : i % 3;
			GridPanel_Numbers->AddChildToUniformGrid(ButtonWidget, Row, Col);
		}
	}

	if (EnterTextArrow)
		EnterTextArrow->OnClicked.AddDynamic(this, &UCodeLockWidget::HandleEnter);
		
	if (RemoveTextArrow)
		RemoveTextArrow->OnClicked.AddDynamic(this, &UCodeLockWidget::HandleRemove);

	if (Button_Exit)
		Button_Exit->OnClicked.AddDynamic(this, &UCodeLockWidget::HandleExit);
}

void UCodeLockWidget::HandleNumberClicked(int32 Number)
{
	if (ClickSound)
	{
		UGameplayStatics::PlaySound2D(this, ClickSound);
	}
	
	if (InputCode.Len() < 4)
	{
		InputCode.AppendInt(Number);
		UpdateTextPassword(); 
	}
}

void UCodeLockWidget::HandleEnter()
{
	if (CodeLockOwner)
	{
		if (CodeLockOwner->CheckPassword(InputCode))
		{
			InputCode.Reset();
			UpdateTextPassword(); 
		}
	}
}

void UCodeLockWidget::HandleRemove()
{
	if (!InputCode.IsEmpty())
	{
		InputCode.RemoveAt(InputCode.Len() - 1);
		UpdateTextPassword(); 
	}
}

void UCodeLockWidget::HandleExit()
{
	SetVisibility(ESlateVisibility::Collapsed);
	
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		PC->bShowMouseCursor = false;
		PC->SetIgnoreMoveInput(false);
		PC->SetIgnoreLookInput(false);
	}
}


void UCodeLockWidget::UpdateTextPassword()
{
	if (Text_Password)
	{
		Text_Password->SetText(FText::FromString(InputCode));
	}
}
