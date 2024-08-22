#include "pch.h"
#include "Ball.h"
#include "Brick.h"
#include "Bar.h"
#include "Wall.h"

Ball::Ball()
:CircleCollider(Vector2(Bar_Center_X, Bar_Center_Y - Bar_Height - Ball_Radius), Ball_Radius)
{
	_brush = CreateSolidBrush(RED);
}

Ball::~Ball()
{
	DeleteObject(_brush);
}

void Ball::Update()
{

	CircleCollider::Update();
	if (GetAsyncKeyState(VK_SPACE))
	{
		_start = true;
	}

	else if (_start)
	{
		_center += _direction * _speed;
	}
}

void Ball::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	CircleCollider::Render(hdc);
}

void Ball::BrickCollision(vector<vector<shared_ptr<Brick>>> bricks)
{
	for (auto brick_X : bricks)
	{
		for (auto brick : brick_X)
		{
			if (brick->_shoot)
				continue;

			if (!this->IsCollision(brick))
				continue;

			float left = brick->_center._x - brick->_halfSize._x;
			float right = brick->_center._x + brick->_halfSize._x;
			float top = brick->_center._y - brick->_halfSize._y;
			float bottom = brick->_center._y + brick->_halfSize._y;

			shared_ptr<Line> top_line = make_shared<Line>(Vector2(left, top), Vector2(right, top));
			shared_ptr<Line> bottom_line = make_shared<Line>(Vector2(left, bottom), Vector2(right, bottom));
			shared_ptr<Line> left_line = make_shared<Line>(Vector2(left, top), Vector2(left, bottom));
			shared_ptr<Line> right_line = make_shared<Line>(Vector2(right, top), Vector2(right, bottom));

			shared_ptr<Line> circle_vertical = make_shared<Line>(Vector2(this->_center._x, this->_center._y - this->_radius), Vector2(this->_center._x, this->_center._y + this->_radius));
			shared_ptr<Line> circle_horizontal = make_shared<Line>(Vector2(this->_center._x - this->_radius, this->_center._y), Vector2(this->_center._x + this->_radius, this->_center._y));

			if (left_line->IsCollision(circle_horizontal).isCollision || right_line->IsCollision(circle_horizontal).isCollision)
			{
				this->_direction._x *= -1;
			}

			else if (top_line->IsCollision(circle_vertical).isCollision || bottom_line->IsCollision(circle_vertical).isCollision)
			{
				this->_direction._y *= -1;
			}
			else
			{
				this->_direction = (this->_center - brick->_center).NormalVector2();
			}

			brick->_shoot = true;
		}
	}
}

void Ball::BarCollision(shared_ptr<class Bar> bar)
{
	float left = bar->_center._x - bar->_halfSize._x;
	float right = bar->_center._x + bar->_halfSize._x;
	float top = bar->_center._y - bar->_halfSize._y;
	shared_ptr<Line> top_line = make_shared<Line>(Vector2(left, top), Vector2(right, top));

	shared_ptr<Line> circle_vertical = make_shared<Line>(Vector2(this->_center._x, this->_center._y - this->_radius), Vector2(this->_center._x, this->_center._y + this->_radius));

	if (top_line->IsCollision(circle_vertical).isCollision)
	{
		this->_direction._y *= -1;
		if (bar->_moving_type == 1)
		{
			this->_direction._x -= 0.5f;
		}
		else if (bar->_moving_type == 2)
		{
			this->_direction._x += 0.5f;
		}
	}
}

void Ball::BorderCollision(vector<shared_ptr<class Wall>> walls)
{
	shared_ptr<Wall> left_wall = walls[0];
	shared_ptr<Wall> right_wall = walls[1];
	shared_ptr<Wall> ceiling = walls[2];

	if (this->IsCollision(left_wall) || this->IsCollision(right_wall))
	{
		this->_direction._x *= -1;
		if (this->_direction._x == 0)
		{
			this->_direction._x = 1;
			_direction.Normalize();
		}
	}
	else if (this->IsCollision(ceiling))
	{
		this->_direction._y *= -1;
	}
}

void Ball::OutofWindow(vector<shared_ptr<class Wall>> walls)
{
	shared_ptr<Wall> floor = walls[3];
	if (this->IsCollision(floor))
	{
		this->_isActive = false;
	}
}
