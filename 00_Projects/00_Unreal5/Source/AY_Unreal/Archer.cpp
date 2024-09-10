// Fill out your copyright notice in the Description page of Project Settings.


#include "Archer.h"
#include "BossMonster.h"

#include "MystatComponent.h"
#include "Engine/DamageEvents.h"

void AArcher::AttackHit()
{
	Super::AttackHit();

	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	float attackRange = 1000.0f;
	float attackRadius = 20.0f;
	float halfheight = attackRange * 0.5f;
	FVector foward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector::UpVector, foward);
	FVector center = GetActorLocation() + foward * halfheight;

	FVector start = GetActorLocation();
	FVector end = start + foward * halfheight;

	bool bResult = GetWorld()->SweepSingleByChannel
	(
		hitResult,
		start,
		end,
		quat,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeCapsule(attackRadius, halfheight),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel() && !hitResult.GetActor()->IsA(AMyPlayer::StaticClass()))
	{
		drawColor = FColor::Red;
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
	}
}

float AArcher::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	SoundManager->Play("ArcherAttack", _hitPoint, FRotator::ZeroRotator);

	return damage;
}
