// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetRandomState.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_SetRandomState::UBTTask_SetRandomState()
{
	NodeName = TEXT("Set Random State");
}

EBTNodeResult::Type UBTTask_SetRandomState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto blackboard = OwnerComp.GetBlackboardComponent();
	if (blackboard == nullptr)
		return EBTNodeResult::Failed;

	int32 originNum = blackboard->GetValueAsInt(FName(TEXT("RandomNum")));
	int32 maxState = blackboard->GetValueAsInt(FName(TEXT("MaxState")));

	int32 randomNum = FMath::Rand() % maxState;

	blackboard->SetValueAsInt(FName(TEXT("RandomNum")), randomNum);

	return result;
}
