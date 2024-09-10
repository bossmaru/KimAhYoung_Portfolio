// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "Creature.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"

#include "MyGameInstance.h"
#include "MyPlayerManager.h"
#include "GameFramework/CharacterMovementComponent.h"


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
		_vertical = _vertical + (creature->GetMovement().X - _vertical) * DeltaSeconds;
		_horizontal = _horizontal + (creature->GetMovement().Y - _horizontal) * DeltaSeconds;
		if (_height != 0.0f)
		{
			_height = (_height + (creature->GetHeight() - _height) * DeltaSeconds) / _height;
		}
		_isDead = (creature->GetcurHP() <= 0);
	}
}

void UMyAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(_myAttackMontage))
	{
		UE_LOG(LogTemp, Warning, TEXT("play attackMontage"));
		Montage_Play(_myAttackMontage);
		ACreature* creature = Cast<ACreature>(TryGetPawnOwner());
		creature->GetCharacterMovement()->DisableMovement();
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

void UMyAnimInstance::PlayMontage(FString montageName)
{
	if (!_Montages.Find(montageName))
		return;

	auto nowPlaying = _Montages[montageName];
	if (!Montage_IsPlaying(nowPlaying))
		Montage_Play(nowPlaying);
}

void UMyAnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Attack%d"), sectionIndex));
	Montage_JumpToSection(sectionName);
}

void UMyAnimInstance::AnimNotify_AttackEnd()
{
	ACreature* creature = Cast<ACreature>(TryGetPawnOwner());
	creature->GetCharacterMovement()->SetDefaultMovementMode();
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