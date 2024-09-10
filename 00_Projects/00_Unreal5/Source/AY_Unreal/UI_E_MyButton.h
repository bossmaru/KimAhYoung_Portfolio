// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UI_E_MyButton.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UUI_E_MyButton : public UButton
{
	GENERATED_BODY()
	
public:
	UUI_E_MyButton();

	void SetIndex(int32 num);
	int32 GetIndex();
	void SetItem(class AMyItem* item);
	class AMyItem* GetItem() { return _itemSetting; }

	UPROPERTY()
	int32 index = -1;

	UPROPERTY()
	class AMyItem* _itemSetting;
};
