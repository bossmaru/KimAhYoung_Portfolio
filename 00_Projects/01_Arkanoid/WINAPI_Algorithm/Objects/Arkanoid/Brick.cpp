#include "pch.h"
#include "Brick.h"
#include "Item.h"

Brick::Brick()
: RectCollider(Vector2(), Vector2(BRICK_WIDTH * 0.5, BRICK_HEIGHT * 0.5))
{
	_brush = CreateSolidBrush(PANTON);
}

Brick::~Brick()
{
	DeleteObject(_brush);
}

void Brick::Update()
{
	RectCollider::Update();
	if (_shoot)
	{
		if (_item)
			_item->_center += Vector2(0, 1) * 12.0f;
	}
	if (_item)
		_item->Update();
}

void Brick::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	RectCollider::Render(hdc);
	if (_item)
		_item->Render(hdc);
}

void Brick::SetPosition(Vector2 pos)
{
	_center = pos;
}

void Brick::SetItem(shared_ptr<class Item> item)
{
	_item = item;
	if (_item)
		_item->_center = _center;
}

shared_ptr<Item> Brick::GetItem()
{
	if (_shoot)
	{
		return _item;
	}
	else
	{
		return nullptr;
	}
}


