#include "pch.h"
#include "Wall.h"

Wall::Wall()
:RectCollider(Vector2(), Vector2())
{
	_brush = CreateSolidBrush(SKYCOLOR);
}

Wall::~Wall()
{
	DeleteObject(_brush);
}

void Wall::Update()
{
	RectCollider::Update();
}

void Wall::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	RectCollider::Render(hdc);
}

void Wall::Resize(Vector2 center, Vector2 halfsize)
{
	_center = center;
	_halfSize = halfsize;
}
