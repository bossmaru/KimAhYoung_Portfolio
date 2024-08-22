// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_PrimeSetting.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UBTService_PrimeSetting : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_PrimeSetting();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
