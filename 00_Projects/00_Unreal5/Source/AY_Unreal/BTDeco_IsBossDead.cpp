// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDeco_IsBossDead.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "BossMonster.h"
#include "MyStatComponent.h"

UBTDeco_IsBossDead::UBTDeco_IsBossDead()
{
	NodeName = TEXT("Is Boss Dead");
}

bool UBTDeco_IsBossDead::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool result = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	
	auto blackboard = OwnerComp.GetBlackboardComponent();
	if (blackboard == nullptr)
		return true;

	auto boss = blackboard->GetValueAsObject(FName(TEXT("Boss")));
	auto Boss = Cast<ABossMonster>(boss);
	if (Boss == nullptr)
		return true;
	if (Boss->GetStatus()->IsDead())
		return true;
	else
		return false;
}
