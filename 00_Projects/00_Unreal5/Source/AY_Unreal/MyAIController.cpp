// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	float canMoveRadius = 2000.0f;

	UBlackboardComponent* temp = Blackboard;
	if (UseBlackboard(_bd, temp))
	{
		if (RunBehaviorTree(_bt))
		{
			UE_LOG(LogTemp, Display, TEXT("behavior Tree"));
		}
	}
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	GetWorld()->GetTimerManager().ClearTimer(_timerHandle);
}
