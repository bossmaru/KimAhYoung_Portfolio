#pragma once
class Wall : public RectCollider
{
public:
	Wall();
	~Wall();

	void Update();
	void Render(HDC hdc);	

	void Resize(Vector2 center, Vector2 halfsize);

private:
	shared_ptr<class Collider> wall;
	HBRUSH _brush;
};

