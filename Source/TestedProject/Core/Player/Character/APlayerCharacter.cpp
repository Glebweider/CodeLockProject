// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "TestedProject/Core/Inventory/Components/Interact/Interface/InteractInterface.h"


AAPlayerCharacter::AAPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	BP_PlayerController = Cast<APlayerController>(GetController());
	
}

void AAPlayerCharacter::HandleInteract_Implementation()
{
	const UCameraComponent* CameraComponent = FindComponentByClass<UCameraComponent>();
	if (CameraComponent && BP_PlayerController)
	{
		int32 ViewportX, ViewportY;
		FVector StartDirection, EndDirection;
	
		BP_PlayerController->GetViewportSize(ViewportX, ViewportY);
		BP_PlayerController->DeprojectScreenPositionToWorld(ViewportX / 2, ViewportY / 2, StartDirection, EndDirection);

		const FRotator CameraRotation = CameraComponent->GetComponentRotation();
		const FVector End = StartDirection + (CameraRotation.Vector() * 220.0f);
		
		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		const bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartDirection, End, ECC_Visibility, CollisionParams);
		if (bHit && !HitResult.GetActor()->GetOwner())
		{
			if (HitResult.GetActor()->Implements<UInteractInterface>())
			{
				IInteractInterface::Execute_Interact(HitResult.GetActor(), this);
			}
		}
	}
}
