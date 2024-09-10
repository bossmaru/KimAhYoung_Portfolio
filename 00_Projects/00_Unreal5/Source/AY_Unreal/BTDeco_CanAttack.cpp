// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDeco_CanAttack.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Creature.h"
#include "MyAIController.h"

UBTDeco_CanAttack::UBTDeco_CanAttack()
{
	NodeName = TEXT("Can Attack");
}

bool UBTDeco_CanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto blackboard = OwnerComp.GetBlackboardComponent();
	if (blackboard == nullptr)
		return false;

	auto target = Cast<ACreature>(blackboard->GetValueAsObject(FName(TEXT("Target"))));
	if (target == nullptr)
		return false;

	auto owner = OwnerComp.GetAIOwner()->GetPawn();
	
	FVector nowPos = owner->GetActorLocation();
	FVector targetPos = target->GetActorLocation();

	return FVector::Distance(nowPos, targetPos) < 300.0f;
}
