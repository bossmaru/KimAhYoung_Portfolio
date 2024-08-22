// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDeco_TargetIsTooFar.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UBTDeco_TargetIsTooFar : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTDeco_TargetIsTooFar();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
};
