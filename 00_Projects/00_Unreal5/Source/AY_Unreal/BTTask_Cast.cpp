// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Cast.h"

#include "Creature.h"
#include "MyAIController.h"
#include "MyAnimInstance.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Cast::UBTTask_Cast()
{
	NodeName = TEXT("Cast Attack");
}

EBTNodeResult::Type UBTTask_Cast::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto owner = Cast<ACreature>(OwnerComp.GetAIOwner()->GetPawn());
	if (owner == nullptr)
		return EBTNodeResult::Failed;

	auto anim = owner->GetAnimInstance();
	if (anim == nullptr)
		return EBTNodeResult::Failed;

	anim->PlayMontage(FString(TEXT("Cast")));

	return result;
}
