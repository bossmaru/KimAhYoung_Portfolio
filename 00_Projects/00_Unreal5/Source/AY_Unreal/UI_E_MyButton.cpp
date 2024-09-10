// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_E_MyButton.h"

UUI_E_MyButton::UUI_E_MyButton()
{
}

void UUI_E_MyButton::SetIndex(int32 num)
{
	index = num;
}

int32 UUI_E_MyButton::GetIndex()
{
	return index;
}

void UUI_E_MyButton::SetItem(AMyItem* item)
{
	_itemSetting = item;
}
