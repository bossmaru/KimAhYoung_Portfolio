// Fill out your copyright notice in the Description page of Project Settings.


#include "VFX_Manager.h"

#include "Effect.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "NiagaraComponent.h"

// Sets default values
AVFX_Manager::AVFX_Manager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_rootComponent = CreateDefaultSubobject<USceneComponent>("RootCom");
	RootComponent = _rootComponent;

	CreateParticleClass(TEXT("Explosion"), TEXT("/Script/Engine.Blueprint'/Game/Blueprint/VFX/Effect_BP.Effect_BP_C'"));
	CreateParticleClass(TEXT("ItemEffect"), TEXT("/Script/Engine.Blueprint'/Game/Blueprint/VFX/ItemEffect_BP.ItemEffect_BP_C'"));
}

// Called when the game starts or when spawned
void AVFX_Manager::BeginPlay()
{
	Super::BeginPlay();

	CreateEffect();
}

void AVFX_Manager::CreateParticleClass(FString name, FString path)
{
	if (_classTable.Contains(name) == true)
	{
		UE_LOG(LogTemp, Error, TEXT("%s already exist in  classTable"), *name);
		return;
	}

	ConstructorHelpers::FClassFinder<AEffect> effect(*path);

	if (effect.Succeeded())
	{
		_classTable.Add(name);
		_classTable[name] = effect.Class;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("can't find %s"), *path);
		return;
	}
}


void AVFX_Manager::CreateEffect()
{
	for (auto classPair : _classTable)
	{
		FString name = classPair.Key;
		_effectTable.Add(name);
		for (int32 i = 0; i < _poolCount; i++)
		{
			FString tempName = FString::Printf(TEXT("%s _ %d"), *name, i);
			FActorSpawnParameters params;
			params.Name = FName(tempName);
			auto effect = GetWorld()->SpawnActor<AEffect>(classPair.Value, FVector::ZeroVector, FRotator::ZeroRotator, params);
			// effect->SetOwner(this);

			effect->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
			_effectTable[name].Add(effect);
		}
	}
}

// Called every frame
void AVFX_Manager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVFX_Manager::Play(FString name, FVector location, FRotator rotator)
{
	if (_effectTable.Contains(name) == false)
		return;

	auto findEffect = _effectTable[name].FindByPredicate([](AEffect* effect)->bool
		{
			if (effect->IsPlaying())
				return false;
			return true;
		});

	if (*findEffect)
		(*findEffect)->Play(location, rotator);
}

