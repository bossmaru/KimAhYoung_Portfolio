#include "pch.h"
#include "Item.h"

Item::Item()
:CircleCollider(Vector2(), 5.0f)
{
	_brushes.push_back(CreateSolidBrush(RGB(255,255,255)));
	_brushes.push_back(CreateSolidBrush(BLUE));
	_brushes.push_back(CreateSolidBrush(GREEN));
	_itemType = ItemType::LongBar;
}

Item::~Item()
{
	for (auto brush : _brushes)
		DeleteObject(brush);
}

void Item::Update()
{
	CircleCollider::Update();
}

void Item::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<int>(_itemType)]);

	if (_isUsed)
		return;
	CircleCollider::Render(hdc);
}

void Item::SetItemType(ItemType itemType)
{
	_itemType = itemType;
}