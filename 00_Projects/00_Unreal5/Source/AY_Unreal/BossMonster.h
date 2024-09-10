// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "BossMonster.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE_TwoParams(AggroDamageDelegate, float, class AMyPlayer*);
DECLARE_MULTICAST_DELEGATE_TwoParams(AggroHpChangedDelegate, float, int32);

UCLASS()
class TEAMHOMEWORK_API ABossMonster : public ACreature
{
	GENERATED_BODY()
	
public:
	ABossMonster();

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	virtual void Tick(float DeltaTime) override;

	void AggroAttack();
	virtual void AttackHit() override;
	virtual float TakeDamage(
		float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser
	) override;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* _trigger;

	UPROPERTY()
	bool _isOverlapped;

	UPROPERTY()
	class AMyPlayer* _originPlayer;

	bool _bossModeStarted = false;

	int32 _aggroNum = 5;
	TArray<TTuple<class AMyPlayer*, int32>> _players;

	AggroDamageDelegate _aggroDamageDelegate;
	AggroHpChangedDelegate _aggroHpChangedDelegate;

private:
	FTimerHandle timerHandle;
};
