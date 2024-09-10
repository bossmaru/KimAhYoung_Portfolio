// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyUIManager.generated.h"

UENUM()
enum class UI_List
{
	//UI List Sorted by "Z-Index".
	//UI will Stack like this list (top to bottom)
	BaseDisplay,
	PlayerSelection,
	AggroInfo,
	Store,
	Inventory,
};

UCLASS()
class TEAMHOMEWORK_API AMyUIManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyUIManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OpenUI(UI_List type);
	void CloseUI(UI_List type);
	void CloseAll();

	class UUI_BaseDisplay* GetBaseDisplay() { return _baseDisplayUI; }
	class UMyInventoryUI* GetInventoryUI() { return _inventoryUI; };
	class UPlayerSelectionUI* GetPlayerSelectionUI() { return _playerSelectionUI; }
	class UMyStoreUI* GetStoreUI() { return _storeUI; }
	class UUI_AggroInfo* GetAggroInfoUI() { return _aggroInfoUI; }

private:
	UPROPERTY()
	TArray<UUserWidget*> _widgets;

	UPROPERTY()
	class UUI_BaseDisplay* _baseDisplayUI;

	UPROPERTY()
	class UMyInventoryUI* _inventoryUI;

	UPROPERTY()
	class UPlayerSelectionUI* _playerSelectionUI;

	UPROPERTY()
	class UMyStoreUI* _storeUI;

	UPROPERTY()
	class UUI_AggroInfo* _aggroInfoUI;
};
