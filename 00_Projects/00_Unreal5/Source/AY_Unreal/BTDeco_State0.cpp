// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDeco_State0.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDeco_State0::UBTDeco_State0()
{
	NodeName = TEXT("State 0");
}

bool UBTDeco_State0::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto blackboard = OwnerComp.GetBlackboardComponent();
	if (blackboard == nullptr)
		return false;

	int32 nowState = blackboard->GetValueAsInt(FName(TEXT("RandomNum")));

	if (nowState == 0)
		return true;
	else
		return false;

	return result;
}
