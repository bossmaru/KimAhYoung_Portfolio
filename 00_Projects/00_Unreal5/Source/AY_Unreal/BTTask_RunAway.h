// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RunAway.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UBTTask_RunAway : public UBTTaskNode
{
	GENERATED_BODY()

public:
    UBTTask_RunAway();

protected:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
    /** Distance to run away from the boss */
    UPROPERTY(EditAnywhere, Category = "RunAway")
    float runDistance = 300.0f;
};
