// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryUI.h"

#include "Components/UniformGridPanel.h"
#include "Components/Widget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/PanelWidget.h"

#include "MyPlayerController.h"

#include "Kismet/GameplayStatics.h"

void UMyInventoryUI::NativeConstruct()
{
	Super::NativeConstruct();

	SetButtons();
}

void UMyInventoryUI::SetButtons()
{
	TArray<UWidget*> widgets;
	widgets = SlotGrid->GetAllChildren();

	for (UWidget* widget : widgets)
	{
		UButton* button = Cast<UButton>(widget);
		if (button)
		{
			_itemButtons.Add(button);
			FItemDetail* itemDetail;
			_itemDetails.Add(itemDetail);
		}
	}
}

void UMyInventoryUI::ToggleVisibility()
{
	AMyPlayerController* playerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (_isVisible)
	{
		this->SetVisibility(ESlateVisibility::Hidden);
		_isVisible = false;

		if (playerController != nullptr)
		{
			playerController->HideUI();
		}
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Visible);
		_isVisible = true;

		if (playerController != nullptr)
		{
			playerController->ShowUI();
		}
	}
}

void UMyInventoryUI::SetItemImage(int32 index)
{
	UImage* image = Cast<UImage>(_itemButtons[index]->GetChildAt(0));
	image->SetBrushFromTexture(_itemDetails[index]->_itemType._texture);
}
