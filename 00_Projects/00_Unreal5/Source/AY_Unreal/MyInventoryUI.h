// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyItem.h"
#include "MyInventoryUI.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UMyInventoryUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	void SetButtons();

	void ToggleVisibility();

	void SetItemImage(int32 index);

	UPROPERTY(meta = (BindWidget))
	class UUniformGridPanel* SlotGrid;

	UPROPERTY()
	TArray<class UButton*> _itemButtons;

	TArray<FItemDetail*> _itemDetails;

	UPROPERTY()
	bool _isVisible = false;
};
