// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestedProject/Core/Builds/Interfaces/ToBuild/ToBuildInterface.h"
#include "TestedProject/Core/Inventory/Components/Interact/Interface/InteractInterface.h"
#include "CodeLock.generated.h"

class UCodeLockWidget;

UCLASS()
class TESTEDPROJECT_API ACodeLock : public AActor, public IInteractInterface, public IToBuildInterface
{
	GENERATED_BODY()

public:
	ACodeLock();

	/** Implements */
	virtual void Interact_Implementation(AActor* CharacterInteract) override;
	
	virtual bool CheckPassword(FString& Input);
	virtual void SetVisibilityWidget(bool bIsVisibility);

protected:
	/** Sounds */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* VerifySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* NotVerifySound;

	/** Door */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CodeLock")
	FString DoorPassword;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CodeLock")
	AActor* DoorActor;

	/** Widgets */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CodeLock")
	TSubclassOf<UUserWidget> CodeLockWidget;
	
	UPROPERTY()
	UCodeLockWidget* Widget;
};
