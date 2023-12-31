﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBlasters/Public/PlayerAnimInstance.h"
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (PlayerCharacter == nullptr)
	{
		PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
	}
	if (PlayerCharacter)
	{
		// Get the lateral speed of the character from velocity
		FVector Velocity{ PlayerCharacter->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		// Is the character in the air?
		bIsInAir = PlayerCharacter->GetCharacterMovement()->IsFalling();

		bIsCrouched = PlayerCharacter->bIsCrouched;

		// Is the character accelerating?
		if (PlayerCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
		{
			bIsAccelerating = true;
		}
		else
		{
			bIsAccelerating = false;
		}

		// Is weapon equipped
		bWeaponEquipped = PlayerCharacter->IsWeaponEquipped();

		AO_Yaw = PlayerCharacter->GetAO_Yaw();
		AO_Pitch = PlayerCharacter->GetAO_Pitch();
	}
}

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
}
