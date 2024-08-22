// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerManager.h"
#include "MyPlayer.h"
#include "Knight.h"
#include "Archer.h"

// Sets default values
AMyPlayerManager::AMyPlayerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyPlayerManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPlayerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UClass* AMyPlayerManager::SetDefaultPawnClass()
{
	FString defaultPath;
	UClass* playerClass;

	switch (_playerType)
	{
	case EPlayerType::Knight:
		defaultPath = TEXT("/Script/Engine.Blueprint'/Game/Blueprint/Player/Knight_BP.Knight_BP_C'");
		playerClass = StaticLoadClass(AKnight::StaticClass(), nullptr, *defaultPath);		break;
	case EPlayerType::Archer:
		defaultPath = TEXT("/Script/Engine.Blueprint'/Game/Blueprint/Player/Archer_BP.Archer_BP_C'");
		playerClass = StaticLoadClass(AArcher::StaticClass(), nullptr, *defaultPath);		break;
	default:
		defaultPath = TEXT("");
		playerClass = nullptr;
	}

	return playerClass;
}

void AMyPlayerManager::SetPlayerType(EPlayerType type)
{
	_playerType = type;
}

EPlayerType AMyPlayerManager::GetPlayerType() const
{
	return EPlayerType();
}
