// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FindBoss.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "MyPlayer.h"
#include "BossMonster.h"
#include "MyAIController.h"

#include "Kismet/GameplayStatics.h"


UBTService_FindBoss::UBTService_FindBoss()
{
	NodeName = TEXT("FindBoss");
	Interval = 0.5f;
}

void UBTService_FindBoss::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto aiOwner = OwnerComp.GetAIOwner()->GetPawn();
	if (aiOwner == nullptr)
		return;

	ABossMonster* boss = Cast<ABossMonster>(UGameplayStatics::GetActorOfClass(GetWorld(), ABossMonster::StaticClass()));

	if (boss)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Boss")), boss);

		FVector bossLocation = boss->GetActorLocation();
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("BossPos")), bossLocation);
	}

	auto player = Cast<AMyPlayer>(aiOwner);
	if (player)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsDamaged"), player->IsDamagedByBoss());
	}
}
