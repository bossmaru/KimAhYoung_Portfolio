#pragma once

#define Ball_Radius 10.0f

class Ball : public CircleCollider
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);
	Vector2 _direction = Vector2(1, -2).NormalVector2();

	void BrickCollision(vector<vector<shared_ptr<class Brick>>> bricks);
	void BarCollision(shared_ptr<class Bar> bar);
	void BorderCollision(vector<shared_ptr<class Wall>> walls);
	void OutofWindow(vector<shared_ptr<class Wall>> walls);

	bool _isUsed = false;
	bool _isActive = false;
	float _speed = 9.0f;
	bool _start = false;

private:
	HBRUSH _brush;
};

