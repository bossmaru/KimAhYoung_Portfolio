#pragma once

#define BRICK_WIDTH  WIN_WIDTH * 0.06f
#define BRICK_HEIGHT 25.0f

#include "Item.h"


class Brick : public RectCollider
{
public:
	Brick();
	~Brick();

	void Update();
	void Render(HDC hdc);

	void SetPosition(Vector2 pos);
	void SetItem(shared_ptr<class Item> item);
	shared_ptr<Item> GetItem();
	bool _shoot = false;

	shared_ptr<Item> _item = nullptr;

private:
	HBRUSH _brush;
};

