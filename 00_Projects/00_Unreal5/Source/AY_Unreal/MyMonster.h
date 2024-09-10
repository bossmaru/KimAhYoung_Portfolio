// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "MyMonster.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API AMyMonster : public ACreature
{
	GENERATED_BODY()
	
public:
	AMyMonster();

	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	virtual void Init() override;
	virtual void Disable() override;

	virtual void AttackHit() override;
	virtual float TakeDamage(
		float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser
	) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	bool _isDead = false;

	UClass* _itemClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UI, meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* _statUpWidget;

private:
	FTimerHandle timerHandle;
};
