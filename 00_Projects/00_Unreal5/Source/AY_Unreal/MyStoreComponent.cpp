// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStoreComponent.h"

#include "MyPlayer.h"
#include "Creature.h"
#include "MyInventoryComponent.h"

// Sets default values for this component's properties
UMyStoreComponent::UMyStoreComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UMyStoreComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyStoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyStoreComponent::OpenShop(AMyPlayer* player)
{
	if (player == nullptr)
		return;

	_playerInven = player->GetInventory();
	_storeInven = Cast<ACreature>(GetOwner())->GetInventory();
}

