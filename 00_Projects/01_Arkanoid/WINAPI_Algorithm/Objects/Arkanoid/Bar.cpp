#include "pch.h"
#include "Bar.h"

Bar::Bar()
: RectCollider(Vector2(Bar_Center_X, Bar_Center_Y), Vector2(Bar_Width, Bar_Height))
{
	_brush = CreateSolidBrush(BLUE);
}

Bar::~Bar()
{
	DeleteObject(_brush);
}

void Bar::Update()
{
	RectCollider::Update();
	Move();
}

void Bar::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	RectCollider::Render(hdc);
}

void Bar::Move()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_center._x += 15.0f;
		_moving_type = (int)MovingType::RIGHT;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_center._x -= 15.0f;
		_moving_type = (int)MovingType::LEFT;
	}
}
