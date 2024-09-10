// Fill out your copyright notice in the Description page of Project Settings.


#include "BossMonster.h"
#include "Components/SphereComponent.h"
#include "MyPlayer.h"
#include "MyStatComponent.h"
#include "MyGameModeBase.h"
#include "Algo/Sort.h"
#include "Engine/DamageEvents.h"
#include "MyAnimInstance.h"
#include "MyStatComponent.h"



ABossMonster::ABossMonster()
{
	PrimaryActorTick.bCanEverTick = true;

	_trigger = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger"));

	_trigger->SetupAttachment(RootComponent);
	_trigger->SetCollisionProfileName(TEXT("MyNPC"));
	_trigger->SetSphereRadius(500.0f);
}

void ABossMonster::BeginPlay()
{
	Super::BeginPlay();

	SetAnimation();
}

void ABossMonster::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	_trigger->OnComponentBeginOverlap.AddDynamic(this, &ABossMonster::OnMyCharacterOverlap);
	
	_statCom->SetHp(500.0f);
}

void ABossMonster::OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	_originPlayer = Cast<AMyPlayer>(OtherActor);
	if (_originPlayer != nullptr)
	{
		FVector bossPos = GetActorLocation();
		auto gameModeBase = Cast<AMyGameModeBase>(GetWorld()->GetAuthGameMode());

		if (gameModeBase && !_bossModeStarted)
		{
			_bossModeStarted = true;
			gameModeBase->StartBossMode(this);
		}
	}
}

void ABossMonster::AggroAttack()
{
	if (!_isAttacking && _animInstance != nullptr)
	{
		_isAttacking = true;

		_animInstance->PlayAttackMontage();

		_curAttackIndex %= 3;
		_curAttackIndex++;

		_animInstance->JumpToSection(_curAttackIndex);
	}
}

void ABossMonster::AttackHit()
{
	_players.RemoveAll([](TTuple<AMyPlayer*, int32> player)
		{ return player.Key->GetStatus()->IsDead(); });

	if (_players.IsEmpty())
		return;

	Algo::Sort(_players, [](const TTuple<AMyPlayer*, int32>& player1, const TTuple<AMyPlayer*, int32>& player2)
		{ return player1.Key->TakenDamageAmount() > player2.Key->TakenDamageAmount(); });

	FHitResult hitResult;

	FCollisionQueryParams params(NAME_None, false, this);

	float attackRange = 500.0f;
	float attackRadius = 1000.0f;

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

	if (bResult && hitResult.GetActor()->IsValidLowLevel() && hitResult.GetActor() == _players[0].Key)
	{
		FDamageEvent damageEvent;

		hitResult.GetActor()->TakeDamage(_statCom->GetAttackDamage(), damageEvent, GetController(), this);
		
		_hitPoint = hitResult.ImpactPoint;
		_attackHitEventDelegate.Broadcast();
		VFXManager->Play("Explosion", _hitPoint);
	}
	
	
	_players[0].Key->DamagedByBoss(true);
	
	GetWorld()->GetTimerManager().SetTimer(timerHandle, FTimerDelegate::CreateLambda([this, player = _players[0].Key]()
		{
			player->DamagedByBoss(false);
		}), 1.0f, false);
	
	_aggroHpChangedDelegate.Broadcast(_statCom->HpRatio(), _players[0].Value);
	
}

float ABossMonster::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	SoundManager->Play("BossAttack", _hitPoint, FRotator::ZeroRotator);

	return damage;
}

void ABossMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
