// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteCodeWidget.h"

void UNoteCodeWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Button_Exit)
		Button_Exit->OnClicked.AddDynamic(this, &UNoteCodeWidget::HandleExit);
}

void UNoteCodeWidget::HandleExit()
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
