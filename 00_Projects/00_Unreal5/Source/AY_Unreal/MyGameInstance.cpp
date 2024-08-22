// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
}

void UMyGameInstance::Init()
{
	Super::Init();

	FActorSpawnParameters params;
	params.Name = TEXT("UIManager");
	_uiManager = GetWorld()->SpawnActor<AMyUIManager>(FVector::ZeroVector, FRotator::ZeroRotator, params);
	
	params.Name = TEXT("PlayerManager");
	_playerManager = GetWorld()->SpawnActor<AMyPlayerManager>(FVector::ZeroVector, FRotator::ZeroRotator, params);
}
