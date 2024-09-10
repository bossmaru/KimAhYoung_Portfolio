// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_BaseDisplay.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UUI_BaseDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	void UpdateNowGold(int amount);
	void UpdateDisplayGold();
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* GoldValue;

private:
	int32 _gold = 0;
};
