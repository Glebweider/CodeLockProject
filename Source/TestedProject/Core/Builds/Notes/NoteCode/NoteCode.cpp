// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteCode.h"

#include "Blueprint/UserWidget.h"
#include "TestedProject/UI/Widgets/Note/NoteCodeWidget.h"


void ANoteCode::Interact_Implementation(AActor* CharacterInteract)
{
	UE_LOG(LogTemp, Display, TEXT("Interact Implementation"));
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	
	if (PC && NoteCodeWidget && CharacterInteract)
	{
		if (Widget)
		{
			if (Widget->IsVisible())
			{
				Widget->SetVisibility(ESlateVisibility::Collapsed);
			} else
			{
				Widget->SetVisibility(ESlateVisibility::Visible);
			}
		} else
		{
			auto NewWidget = CreateWidget<UUserWidget>(PC, NoteCodeWidget);
			if (NewWidget)
			{
				NewWidget->AddToViewport();
				
				Widget = Cast<UNoteCodeWidget>(NewWidget);
			}
		}

		bool bIsVisibility = Widget->IsVisible();
		
		PC->bShowMouseCursor = bIsVisibility;
		PC->SetIgnoreMoveInput(bIsVisibility);
		PC->SetIgnoreLookInput(bIsVisibility);
	}
}
