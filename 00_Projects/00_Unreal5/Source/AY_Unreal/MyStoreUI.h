// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyStoreUI.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UMyStoreUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	void ToggleVisibility();

	UPROPERTY()
	bool _isVisible = false;
};
