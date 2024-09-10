// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryUI.h"

#include "Components/UniformGridPanel.h"
#include "Components/Widget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"

#include "UI_E_MyButton.h"
#include "MyPlayerController.h"

#include "Kismet/GameplayStatics.h"

#include "MyGameInstance.h"
#include "VFX_Manager.h"

#include "MyPlayer.h"

UMyInventoryUI::UMyInventoryUI(const FObjectInitializer& ObjectInitializer)
:UUserWidget(ObjectInitializer)
{
	SetDefaultTexture();
	_defaultText = TEXT("-");
}

void UMyInventoryUI::NativeConstruct()
{
	Super::NativeConstruct();
	
	
}

bool UMyInventoryUI::Initialize()
{
	bool result = Super::Initialize();

	SetButtons();
	
	Button_[0]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem0);
	Button_[1]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem1);
	Button_[2]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem2);
	Button_[3]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem3);
	Button_[4]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem4);
	Button_[5]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem5);
	Button_[6]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem6);
	Button_[7]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem7);
	Button_[8]->OnClicked.AddDynamic(this, &UMyInventoryUI::SetTargetItem8);

	DropButton->OnClicked.AddDynamic(this, &UMyInventoryUI::DropItem);
	UseButton->OnClicked.AddDynamic(this, &UMyInventoryUI::UseItem);

	return result;
}

void UMyInventoryUI::SetButtons()
{
	TArray<UWidget*> widgets;
	widgets = SlotGrid->GetAllChildren();

	int32 index = 0;
	for (UWidget* widget : widgets)
	{
		UUI_E_MyButton* button = Cast<UUI_E_MyButton>(widget);
		if (button)
		{
			button->SetIndex(index);
			button->SetIsEnabled(true);
			//button->OnClicked.AddDynamic(this, UMyInventoryUI::ShowItem);
			Button_.Add(button);

			UImage* image = Cast<UImage>(button->GetChildAt(0));
			if (image)
			{
				Image_.Add(image);
			}
			index++;
		}
	}
}

void UMyInventoryUI::SetDefaultTexture()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> texture(
		TEXT("/Script/Engine.Texture2D'/Game/Graphics/Icons/Tex_efault.Tex_Default'")
	);
	if (texture.Succeeded())
	{
		_defaultTexture = texture.Object;
	}
}

void UMyInventoryUI::SetItemImage(int32 inventoryIndex, AMyItem* item)
{
	//UImage* image = Cast<UImage>(Button_[inventoryIndex]->GetChildAt(0));
	
	if (item == nullptr)
	{
		Button_[inventoryIndex]->SetItem(nullptr);
		Image_[inventoryIndex]->SetBrushFromTexture(_defaultTexture);
	}
	else
	{
		Button_[inventoryIndex]->SetItem(item);
		UTexture2D* itemTexture = item->GetItemTexture();
		Image_[inventoryIndex]->SetBrushFromTexture(itemTexture);
	}
}

void UMyInventoryUI::DropItem()
{
	if (_targetItem == nullptr)
		return;
	itemDROP.Broadcast();

	//TODO : Why It is can't read it.
	if(itemDropIndex.IsBound())
		itemDropIndex.Execute(_targetIndex);

	_targetItem = nullptr;
	ShowItem();
	SetItemImage(_targetIndex, nullptr);
	_targetIndex = -1;
}

void UMyInventoryUI::UseItem()
{
	if (_targetItem == nullptr)
		return;
	itemUSE.Broadcast();
	if(itemUseIndex.IsBound())
		itemUseIndex.Execute(_targetIndex);

	_targetItem = nullptr;
	ShowItem();
	SetItemImage(_targetIndex, nullptr);
	_targetIndex = -1;

	AMyPlayer* originPlayer = Cast<AMyPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	VFXManager->Play("ItemEffect", originPlayer->GetActorLocation());
}

void UMyInventoryUI::ShowItem()
{
	FString itemName;
	UTexture2D* itemTexture;
	if (_targetItem == nullptr)
	{
		itemName = _defaultText;
		itemTexture = _defaultTexture;
	}
	else
	{
		itemName = _targetItem->GetItemName();
		itemTexture = _targetItem->GetItemTexture();
	}

	Text_itemName->SetText(FText::FromString(itemName));
	Item_texture->SetBrushFromTexture(itemTexture);
}

void UMyInventoryUI::SetTargetItem0()
{
	AMyItem* item = Button_[0]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 0;
	ShowItem();
}

void UMyInventoryUI::SetTargetItem1()
{
	AMyItem* item = Button_[1]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 1;
	ShowItem();
}

void UMyInventoryUI::SetTargetItem2()
{
	AMyItem* item = Button_[2]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 2;
	ShowItem();
}

void UMyInventoryUI::SetTargetItem3()
{
	AMyItem* item = Button_[3]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 3;
	ShowItem();
}

void UMyInventoryUI::SetTargetItem4()
{
	AMyItem* item = Button_[4]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 4;
	ShowItem();
}

void UMyInventoryUI::SetTargetItem5()
{
	AMyItem* item = Button_[5]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 5;
	ShowItem();
}

void UMyInventoryUI::SetTargetItem6()
{
	AMyItem* item = Button_[6]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 6;
	ShowItem();
}

void UMyInventoryUI::SetTargetItem7()
{
	AMyItem* item = Button_[7]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 7;
	ShowItem();
}

void UMyInventoryUI::SetTargetItem8()
{
	AMyItem* item = Button_[8]->GetItem();
	if (item == nullptr)
		return;
	_targetItem = item;
	_targetIndex = 8;
	ShowItem();
}
