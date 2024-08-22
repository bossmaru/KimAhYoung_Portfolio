// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetTargetPos.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Creature.h"

UBTTask_SetTargetPos::UBTTask_SetTargetPos()
{
	NodeName = TEXT("SetTargetPos");
}

EBTNodeResult::Type UBTTask_SetTargetPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto blackboard = OwnerComp.GetBlackboardComponent();
	auto target = Cast<ACreature>(blackboard->GetValueAsObject(FName(TEXT("Target"))));
	float maxRange = blackboard->GetValueAsFloat(FName(TEXT("MaxRange")));
	FVector primePos = blackboard->GetValueAsVector(FName("PrimePos"));

	if (target == nullptr)
		return EBTNodeResult::Failed;

	FVector targetPos = target->GetActorLocation();

	float dist = FVector::Dist(primePos, targetPos);
	//if target is too far, return to prime position
	if (dist >= maxRange)
		blackboard->SetValueAsVector(FName(TEXT("TargetPos")), primePos);

	blackboard->SetValueAsVector(FName(TEXT("TargetPos")), targetPos);

	return EBTNodeResult::Succeeded;

	return result;
}
