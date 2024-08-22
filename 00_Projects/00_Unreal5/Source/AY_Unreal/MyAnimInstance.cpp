// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "Creature.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"

#include "MyGameInstance.h"
#include "MyPlayerManager.h"

UMyAnimInstance::UMyAnimInstance()
{
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	ACreature* creature = Cast<ACreature>(TryGetPawnOwner());
	if (creature != nullptr)
	{
		_speed = creature->GetVelocity().Size();
		_isFalling = creature->GetMovementComponent()->IsFalling();
		_vertical = _vertical + (creature->_vertical - _vertical) * DeltaSeconds;
		_horizontal = _horizontal + (creature->_horizontal - _horizontal) * DeltaSeconds;
		_height = (_height + (creature->_height - _height) * DeltaSeconds) / _height;
		_isDead = (creature->GetcurHP() <= 0);
	}
}

void UMyAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(_myAttackMontage))
	{
		Montage_Play(_myAttackMontage);
	}
}

void UMyAnimInstance::PlayDamagedMontage()
{
	if (!Montage_IsPlaying(_myDamagedMontage))
	{
		UE_LOG(LogTemp, Display, TEXT("Damaged Montage"));
		Montage_Play(_myDamagedMontage);
	}
}

void UMyAnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Attack%d"), sectionIndex));
	Montage_JumpToSection(sectionName);
}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	_attackDelegate.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Attack Hit!"));
}

void UMyAnimInstance::AnimNotify_Death()
{
	_deathDelegate.Broadcast();
	UE_LOG(LogTemp, Error, TEXT("Death!"));
}