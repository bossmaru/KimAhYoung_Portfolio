// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryComponent.h"
#include "MyItem.h"

// Sets default values for this component's properties
UMyInventoryComponent::UMyInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UMyInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyInventoryComponent::AddItem(AMyItem* item)
{
	if (item)
	{
		_items.Add(item);
		item->SetActorHiddenInGame(true);
		item->SetActorEnableCollision(false);
	}
}

void UMyInventoryComponent::DropItem()
{
	if (_items.Num() > 0)
	{
		AMyItem* item = _items[0];
		if (item)
		{
			item->SetActorHiddenInGame(false);
			item->SetActorEnableCollision(true);

			FVector playerPlos = GetOwner()->GetActorLocation();

			float randFloat = FMath::FRandRange(0, PI * 2.0f);

			float X = cosf(randFloat) * 300.0f;
			float Y = sinf(randFloat) * 300.0f;
			FVector itemPos = playerPlos + FVector(X, Y, 0.0f);
			itemPos.Z = 0.0f;
			item->SetActorLocation(itemPos);

			_items.Remove(item);
		}
	}
}

