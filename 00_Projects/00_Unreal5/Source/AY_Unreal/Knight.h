// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayer.h"
#include "Knight.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API AKnight : public AMyPlayer
{
	GENERATED_BODY()

	
public:
	virtual void BeginPlay() override;
	virtual void AttackHit() override;

	virtual float TakeDamage(
		float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser
	) override;
};
