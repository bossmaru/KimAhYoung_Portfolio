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

	virtual void BeginPlay() override;
};
