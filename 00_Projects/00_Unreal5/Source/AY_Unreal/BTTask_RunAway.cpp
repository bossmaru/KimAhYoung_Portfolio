// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RunAway.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "MyAIController.h"
#include "MyPlayer.h"

UBTTask_RunAway::UBTTask_RunAway()
{
	NodeName = TEXT("Run Away");
}

EBTNodeResult::Type UBTTask_RunAway::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    auto aiController = OwnerComp.GetAIOwner();
    if (aiController)
    {
        APawn* ControlledPawn = aiController->GetPawn();
        if (ControlledPawn)
        {
            FVector bossPos = aiController->GetBlackboardComponent()->GetValueAsVector("BossPos");

            FVector runDirection = ControlledPawn->GetActorLocation() - bossPos;
            runDirection.Normalize();

            FVector runDestination = ControlledPawn->GetActorLocation() + runDirection * runDistance;

            aiController->MoveToLocation(runDestination);

            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}
