// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SetRandomPos.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UBTTask_SetRandomPos : public UBTTaskNode
{
	GENERATED_BODY()
	
	UBTTask_SetRandomPos();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
