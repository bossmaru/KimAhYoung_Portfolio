// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SetTargetPos.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UBTTask_SetTargetPos : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_SetTargetPos();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
