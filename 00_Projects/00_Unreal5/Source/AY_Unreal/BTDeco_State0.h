// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDeco_State0.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UBTDeco_State0 : public UBTDecorator
{
	GENERATED_BODY()
	
	UBTDeco_State0();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
};
