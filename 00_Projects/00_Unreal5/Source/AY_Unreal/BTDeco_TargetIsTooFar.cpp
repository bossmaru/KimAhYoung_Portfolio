// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDeco_TargetIsTooFar.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Creature.h"
#include "MyAIController.h"

UBTDeco_TargetIsTooFar::UBTDeco_TargetIsTooFar()
{
	NodeName = TEXT("Is Target Too Far");
}

bool UBTDeco_TargetIsTooFar::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto blackboard = OwnerComp.GetBlackboardComponent();
	if (blackboard == nullptr)
		return true;

	auto target = Cast<ACreature>(blackboard->GetValueAsObject(FName("Target")));
	if (target == nullptr)
		return true;

	FVector nowPos = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	FVector targetPos = target->GetActorLocation();
	float maxSearchRange = blackboard->GetValueAsFloat(FName("MaxRange"));

	float dist = FVector::Dist(nowPos, targetPos);

	if (dist - maxSearchRange > 0)
		return true;
	else
		return false;
}
