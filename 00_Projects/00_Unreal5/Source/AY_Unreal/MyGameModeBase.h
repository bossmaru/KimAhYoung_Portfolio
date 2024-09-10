// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */

UCLASS()
class TEAMHOMEWORK_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameModeBase();

	virtual void BeginPlay() override;

	void SpawnItem(FVector Location, FRotator Rotation, int32 itemCode);

	void SetSelectedPlayer();

	void StartBossMode(class ABossMonster* boss);

private:
	UClass* _itemClass;
	TArray<class AMyItem*> _items;
};
