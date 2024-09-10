// Fill out your copyright notice in the Description page of Project Settings.


#include "Creature.h"

#include "Materials/MaterialParameterCollection.h"

#include "MyAnimInstance.h"
#include "MyAIController.h"
#include "MyInventoryComponent.h"
#include "MyStatComponent.h"
#include "MyHpBar.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/Button.h"

#include "GameFramework/Controller.h"

#include "Engine/DamageEvents.h"

#include "MyGameInstance.h"

// Sets default values
ACreature::ACreature()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	 
	//Stat
	_statCom = CreateDefaultSubobject<UMyStatComponent>(TEXT("Stat"));
	//Inventory
	_inventoryCom = CreateDefaultSubobject<UMyInventoryComponent>(TEXT("Inventory"));

	//hpbar
	_hpBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	_hpBarWidget->SetupAttachment(GetMesh());
	_hpBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	_hpBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 200.0f));

	static ConstructorHelpers::FClassFinder<UUserWidget> hpBar(
		TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/MyHpBar_BP.MyHpBar_BP_C'")
	);
	if (hpBar.Succeeded())
	{
		_hpBarWidget->SetWidgetClass(hpBar.Class);
	}

	//AI
	APawn::AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

//Called when the game starts or when spawned
void ACreature::BeginPlay()
{
	Super::BeginPlay();
}

void ACreature::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	_statCom->SetLevelAndInit(1);

	_hpBarWidget->InitWidget();
	auto hpBar = Cast<UMyHpBar>(_hpBarWidget->GetUserWidgetObject());
	if (hpBar && _statCom)
	{
		_statCom->_hpChangedDelegate.AddUObject(hpBar, &UMyHpBar::SetHpBarValue);
	}
}

void ACreature::SetAnimation()
{
	_animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());

	if (_animInstance->IsValidLowLevel())
	{
		_animInstance->OnMontageEnded.AddDynamic(this, &ACreature::OnAttackEnded);
		_animInstance->_attackDelegate.AddUObject(this, &ACreature::AttackHit);
		_animInstance->_deathDelegate.AddUObject(this, &ACreature::Disable);
	}
}

void ACreature::Init()
{
	_statCom->Reset();

	_isActive = true;
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	PrimaryActorTick.bCanEverTick = true;

	_statCom->_deathDelegate.AddUObject(this, &ACreature::Unpossess);
}

void ACreature::Disable()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	PrimaryActorTick.bCanEverTick = false;

	Unpossess();
}

void ACreature::Unpossess()
{
	if (GetController() == nullptr)
		return;

	GetController()->UnPossess();
}

// Called every frame
void ACreature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACreature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACreature::OnAttackEnded(UAnimMontage* Montage, bool bInterrupted)
{
	UE_LOG(LogTemp, Log, TEXT("Attack Ended!"));
	_isAttacking = false;

	_attackEndedDelegate.Broadcast();
}

void ACreature::AttackHit()
{
}

void ACreature::AI_Attack()
{
	if (_statCom->IsDead())
		return;
	if (!_isAttacking && _animInstance != nullptr)
	{
		_isAttacking = true;
		_animInstance->PlayAttackMontage();

		_curAttackIndex %= 3;
		_curAttackIndex++;

		_animInstance->JumpToSection(_curAttackIndex);
	}
}

float ACreature::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	float damaged = -_statCom->AddCurHP(-Damage);

	if (_animInstance != nullptr && _statCom->GetCurHP() > 0)
	{
		_animInstance->PlayDamagedMontage();
	}

	if (_animInstance != nullptr && _statCom->GetCurHP() <= 0)
	{
		_statCom->AddCurHP(-999);
		_isActive = false;
		Unpossess();
	}

	return damage;
}

int32 ACreature::GetcurHP()
{
	if (!_statCom)
		return 0;

	return _statCom->GetCurHP();
}

