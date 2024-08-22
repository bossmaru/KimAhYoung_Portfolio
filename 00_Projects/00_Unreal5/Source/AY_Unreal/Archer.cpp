// Fill out your copyright notice in the Description page of Project Settings.


#include "Archer.h"

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

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		drawColor = FColor::Red;
		UE_LOG(LogTemp, Log, TEXT("HitActor : %s"), *hitResult.GetActor()->GetName());

		FDamageEvent damageEvent;
		hitResult.GetActor()->TakeDamage(_statCom->GetAttackDamage(), damageEvent, GetController(), this);
		_hitPoint = hitResult.ImpactPoint;

		DrawDebugCapsule(GetWorld(), center, attackRange * 0.5f, attackRadius, quat, FColor::Red, false, 2.0f);
	}

	else
	{
		DrawDebugCapsule(GetWorld(), center, attackRange * 0.5f, attackRadius, quat, FColor::Green, false, 2.0f);
	}
}
