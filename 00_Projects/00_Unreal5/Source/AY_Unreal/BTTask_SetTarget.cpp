// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetTarget.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "MyPlayer.h"
#include "BossMonster.h"
#include "MyAIController.h"

UBTTask_SetTarget::UBTTask_SetTarget()
{
	NodeName = TEXT("SetTarget");
}

EBTNodeResult::Type UBTTask_SetTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto aiOwner = OwnerComp.GetAIOwner()->GetPawn();
	if (aiOwner == nullptr)
		return EBTNodeResult::Failed;

	auto boss = Cast<ABossMonster>(aiOwner);
	if (boss)
	{
		if(!boss->_players.IsEmpty())
		{ 
			auto targetPlayer = (boss->_players)[0].Key;
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), targetPlayer);
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("TargetPos")), targetPlayer->GetActorLocation());
		}
	}

	return EBTNodeResult::Type();
}
