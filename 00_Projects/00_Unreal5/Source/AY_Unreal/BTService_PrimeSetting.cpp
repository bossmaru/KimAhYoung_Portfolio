// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PrimeSetting.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Creature.h"
#include "MyAIController.h"

UBTService_PrimeSetting::UBTService_PrimeSetting()
{
	NodeName = TEXT("Prime Setting");
}

void UBTService_PrimeSetting::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto aiOwner = OwnerComp.GetAIOwner()->GetPawn();
	if (aiOwner == nullptr)
		return;
	FVector primePos = aiOwner->GetActorLocation();
	float maxRange = 1000.0f;

	auto blackboard = OwnerComp.GetBlackboardComponent();
	if (blackboard == nullptr)
		return;

	bool isPrimeSetted = blackboard->GetValueAsBool(FName("IsFirstUpdated"));
	if (!isPrimeSetted)
	{
		blackboard->SetValueAsVector(FName("PrimePos"), primePos);
		blackboard->SetValueAsFloat(FName("MaxRange"), maxRange);
		blackboard->SetValueAsBool(FName("IsFirstUpdated"), true);
	}
}
