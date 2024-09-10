// Fill out your copyright notice in the Description page of Project Settings.


#include "Knight.h"
#include "BossMonster.h"
#include "MystatComponent.h"
#include "Engine/DamageEvents.h"
#include "UI_AggroInfo.h"

void AKnight::BeginPlay()
{
	Super::BeginPlay();

	_statCom->SetMaxHp(1000);
	_statCom->AddAttackDamage(20.0f);
}

void AKnight::AttackHit()
{
	Super::AttackHit();

	FHitResult hitResult;

	FCollisionQueryParams params(NAME_None, false, this);

	float attackRange = 150.0f;
	float attackRadius = 50.0f;

	bool bResult = GetWorld()->SweepSingleByChannel
	(
		hitResult,
		GetActorLocation() + GetActorForwardVector() * attackRange,
		GetActorLocation() + GetActorForwardVector() * attackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(attackRadius),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel() && !hitResult.GetActor()->IsA(AMyPlayer::StaticClass()))
	{
		FDamageEvent damageEvent;

		float baseDamage = _statCom->GetAttackDamage();
		float finalDamage = baseDamage;

		ABossMonster* boss = Cast<ABossMonster>(hitResult.GetActor());
		if (boss)
		{
			float randomFactor = FMath::RandRange(0.8f, 1.2f);
			finalDamage = baseDamage * randomFactor;
			_damageToBoss += finalDamage;
			boss->_aggroDamageDelegate.Broadcast(_damageToBoss, this);
		}

		hitResult.GetActor()->TakeDamage(finalDamage, damageEvent, GetController(), this);

		_hitPoint = hitResult.ImpactPoint;
		_attackHitEventDelegate.Broadcast();
		VFXManager->Play("Explosion", _hitPoint);

		drawColor = FColor::Red;
	}

	FVector center = GetActorLocation() + GetActorForwardVector() * attackRange;
	
}

float AKnight::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	SoundManager->Play("KnightAttack", _hitPoint, FRotator::ZeroRotator);

	return damage;
}
