// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AggroAttack.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "BossMonster.h"
#include "MyAIController.h"

UBTTask_AggroAttack::UBTTask_AggroAttack()
{
	NodeName = TEXT("AggroAttack";)
}

EBTNodeResult::Type UBTTask_AggroAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto owner = Cast<ABossMonster>(OwnerComp.GetAIOwner()->GetCharacter());

	if (owner == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	owner->AggroAttack();

	owner->_attackEndedDelegate.AddLambda(
		[this]()->void { this->_isAttacking = false; }
	);

	return EBTNodeResult::Type();

}

void UBTTask_AggroAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (_isAttacking == false)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
