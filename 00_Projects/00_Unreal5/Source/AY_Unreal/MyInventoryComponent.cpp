// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryComponent.h"

#include "MyGameInstance.h"

#include "MyPlayer.h"
#include "MyItem.h"
#include "MyInventoryUI.h"

// Sets default values for this component's properties
UMyInventoryComponent::UMyInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UTexture2D> texture(
		TEXT("/Script/Engine.Texture2D'/Game/Graphics/Icons/Tex_Default.Tex_Default'")
	);
	if (texture.Succeeded())
	{
		_defaultTexture = texture.Object;
	}
}

// Called when the game starts
void UMyInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	UIManager->GetInventoryUI()->itemDropIndex.BindUObject(this, &UMyInventoryComponent::DropItemOfSlot);
	UIManager->GetInventoryUI()->itemUseIndex.BindUObject(this, &UMyInventoryComponent::UseItemOfSlot);
	
}

void UMyInventoryComponent::AddItem(AMyItem* item)
{

	//If there is Empty Slot, Add item there first.
	if (!_emptySlots.IsEmpty())
	{
		int32 putSlot;
		_emptySlots.HeapPop(putSlot, true);
		_items[putSlot] = item;
		UIManager->GetInventoryUI()->SetItemImage(putSlot, item);
	}
	else if (_items.Num() <= _inventoryMax)
	{
		_items.Add(item);
		int32 itemStack = _items.Num() - 1;
		UIManager->GetInventoryUI()->SetItemImage(itemStack, item);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Inventory is Full!"));
	}
}

void UMyInventoryComponent::DropItem()
{
	if (_items.IsEmpty())
		return;

	int32 lastPos = _items.Num();
	AMyItem* item = _items.Pop();

	FVector playerPlos = GetOwner()->GetActorLocation();

	float randFloat = FMath::FRandRange(0, PI * 2.0f);

	float X = cosf(randFloat) * 300.0f;
	float Y = sinf(randFloat) * 300.0f;
	FVector itemPos = playerPlos + FVector(X, Y, 0.0f);
	itemPos.Z = 50.0f;

	item->ReleaseItem(itemPos);
	UIManager->GetInventoryUI()->SetItemImage(lastPos, nullptr);
}

void UMyInventoryComponent::DropItemOfSlot(int32 slotNum)
{
	if (_items.IsEmpty())
		return;

	if (slotNum > _items.Num())
		return;

	AMyItem* item = _items[slotNum];
	if (item == nullptr)
		return;

	FVector playerPlos = GetOwner()->GetActorLocation();
	float randFloat = FMath::FRandRange(0, PI * 2.0f);
	float X = cosf(randFloat) * 300.0f;
	float Y = sinf(randFloat) * 300.0f;
	FVector itemPos = playerPlos + FVector(X, Y, 0.0f);
	itemPos.Z = 50.0f;
	item->ReleaseItem(itemPos);

	_items[slotNum] = nullptr;
	_emptySlots.Add(slotNum);
	//UIManager->GetInventoryUI()->SetItemImage(slotNum, nullptr);
	UE_LOG(LogTemp, Warning, TEXT("Item Drop Success!"));
}

void UMyInventoryComponent::UseItemOfSlot(int32 slotNum)
{
	if (_items.IsEmpty())
		return;

	if (slotNum > _items.Num())
		return;

	AMyItem* item = _items[slotNum];
	if (item == nullptr)
		return;

	item->UseItem();

	_items[slotNum] = nullptr;
	_emptySlots.Add(slotNum);
	//UIManager->GetInventoryUI()->SetItemImage(slotNum, nullptr);
	UE_LOG(LogTemp, Warning, TEXT("Item Remove Success!"));
}

UTexture2D* UMyInventoryComponent::GetItemTexture(int32 slotNum)
{
	if (slotNum > _items.Num() || _items[slotNum] == nullptr)
		return _defaultTexture;
	return _items[slotNum]->GetItemTexture();
}

FString UMyInventoryComponent::GetItemName(int32 slotNum)
{
	if (slotNum > _items.Num() || _items[slotNum] == nullptr)
		return FString(TEXT(""));
	return _items[slotNum]->GetItemName();
}

int32 UMyInventoryComponent::GetItemPrice(int32 slotNum)
{
	if (slotNum > _items.Num() || _items[slotNum] == nullptr)
		return 0;
	return _items[slotNum]->GetItemPrice();
}

