// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetRandomPos.h"

#include "NavigationSystem.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Creature.h"
#include "MyAIController.h"

UBTTask_SetRandomPos::UBTTask_SetRandomPos()
{
	NodeName = TEXT("Set Random Position");
}

EBTNodeResult::Type UBTTask_SetRandomPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto blackboard = OwnerComp.GetBlackboardComponent();
	if (blackboard == nullptr)
		return EBTNodeResult::Failed;

	auto aiOwner = OwnerComp.GetAIOwner()->GetPawn();
	if (!aiOwner->IsValidLowLevel())
		return EBTNodeResult::Failed;

	FVector primePos = blackboard->GetValueAsVector(FName(TEXT("PrimePos")));
	FVector nowPos = aiOwner->GetActorLocation();
	float radius = 200.0f;
	float maxRange = blackboard->GetValueAsFloat(FName(TEXT("MaxRange")));

	auto NaviSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if(NaviSystem == nullptr)
		return EBTNodeResult::Failed;

	FNavLocation randomLoc;

	NaviSystem->GetRandomPointInNavigableRadius(nowPos, radius, randomLoc);
	
	FVector randomPos = randomLoc.Location;

	float dist = FVector::Distance(randomPos, primePos);

	if(dist <= maxRange)
		blackboard->SetValueAsVector(FName("RandomPos"), randomPos);
	else
		blackboard->SetValueAsVector(FName("RandomPos"), primePos);

	return result;
}
