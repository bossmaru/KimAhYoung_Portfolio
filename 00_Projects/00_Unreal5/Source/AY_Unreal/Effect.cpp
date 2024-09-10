// Fill out your copyright notice in the Description page of Project Settings.


#include "Effect.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"

// Sets default values
AEffect::AEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_particleCom = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));

	RootComponent = _particleCom;

	_niagaraCom = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Niagara"));
	_niagaraCom->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEffect::BeginPlay()
{
	Super::BeginPlay();
	
	_particleCom->OnSystemFinished.AddDynamic(this, &AEffect::EndParticle);
	EndParticle(_particleCom);

	_niagaraCom->OnSystemFinished.AddDynamic(this, &AEffect::EndNiagara);
	EndNiagara(_niagaraCom);
}

// Called every frame
void AEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEffect::Play(FVector location, FRotator rotation)
{
	if (_particleCom->IsActive() || _niagaraCom->IsActive())
		return;

	SetActorLocationAndRotation(location, rotation);

	if(_particleCom)
		_particleCom->ActivateSystem();
	if(_niagaraCom)
		_niagaraCom->ActivateSystem();
}

void AEffect::EndParticle(UParticleSystemComponent* particle)
{
	if (particle)
		particle->DeactivateSystem();
}

void AEffect::EndNiagara(UNiagaraComponent* niagara)
{
	if (niagara)
		niagara->Deactivate();
}


bool AEffect::IsPlaying()
{
	return _particleCom->IsActive() || _niagaraCom->IsActive();
}

