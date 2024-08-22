// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FindTarget.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "MyAIController.h"
#include "MyPlayer.h"
#include "MyMonster.h"

#include "Engine/OverlapResult.h"

//debug
#include "DrawDebugHelpers.h"

UBTService_FindTarget::UBTService_FindTarget()
{
	NodeName = TEXT("FindTargetPlayer");
	Interval = 0.5f;
}

void UBTService_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto aiOwner = OwnerComp.GetAIOwner()->GetPawn();
	if (aiOwner == nullptr)
		return;

	auto world = GetWorld();
	if (world == nullptr)
		return;

	FVector center = aiOwner->GetActorLocation();
	float searchRadius = 1000.0f;
	auto brush = FColor::Green;

	TArray<FOverlapResult> overlapResult;
	FCollisionQueryParams colParam(NAME_None, false, aiOwner);
	bool bResult = world->OverlapMultiByChannel(
		overlapResult,
		center,
		FQuat::Identity,
		ECollisionChannel::ECC_EngineTraceChannel2,
		FCollisionShape::MakeSphere(searchRadius),
		colParam
	);

	if (bResult)
	{
		for (auto result : overlapResult)
		{
			//for monster
			auto target = Cast<AMyPlayer>(result.GetActor());
			//for player ai
			//auto target = Cast<AMyMonster>(result.GetActor());
			if (target)
			{
				auto targetController = target->GetController();
				if (targetController != nullptr)
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), target);
					brush = FColor::Red;
				}
			}
		}
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);
		brush = FColor::Green;
	}
	DrawDebugSphere(
		world,
		center,
		searchRadius,
		32,
		brush,
		false,
		0.3f
	);
}
