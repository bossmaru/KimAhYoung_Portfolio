// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerSelectionUI.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UPlayerSelectionUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual void NativeConstruct() override;

protected:
    UPROPERTY(meta = (BindWidget))
    class UUniformGridPanel* SlotGrid;

    UFUNCTION()
    void OnKnightButtonClicked();

    UFUNCTION()
    void OnArcherButtonClicked();

    void SetPlayer();
};
