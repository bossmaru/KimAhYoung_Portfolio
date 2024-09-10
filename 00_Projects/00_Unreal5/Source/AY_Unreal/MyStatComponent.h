// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyStatComponent.generated.h"

USTRUCT()
struct FMyStatData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 maxHp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 attack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 gold;
};


DECLARE_MULTICAST_DELEGATE_OneParam(HpChanged, float);
DECLARE_MULTICAST_DELEGATE(DeathDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAMHOMEWORK_API UMyStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Reset();

	void SetMaxHp(int32 hp) { _maxhp = hp; };
	void SetHp(int32 hp);
	int32 GetCurHP() { return _curhp; }
	int32 GetAttackDamage() { return _atk; }
	float HpRatio() const { return _curhp / (float)_maxhp; }

	void SetLevelAndInit(int level);

	int AddCurHP(float amount);
	void AddAttackDamage(float amount);
	void AddSpeed(float amount);
	bool IsDead() { return _curhp <= 0; }

	void AddGold(int32 amount);
	int32 ShowGold() { return _gold; }

	HpChanged _hpChangedDelegate;
	DeathDelegate _deathDelegate;

	//Stats
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
	int32 _curhp = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat, meta = (AllowPrivateAccess = "true"))
	int32 _maxhp = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat, meta = (AllowPrivateAccess = "true"))
	int32 _atk_default = 5;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
	int32 _atk = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
	int32 _speed = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat, meta = (AllowPrivateAccess = "true"))
	int32 _gold = 0;
};
