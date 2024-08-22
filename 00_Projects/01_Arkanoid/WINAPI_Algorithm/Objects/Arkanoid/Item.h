#pragma once

enum class ItemType
{
	LongBar,
	DoubleBall,
	TripleBall,
};

class Item : public CircleCollider
{
public:
	Item();
	~Item();

	void Update();
	void Render(HDC hdc);

	void SetItemType(ItemType itemType);
	ItemType GetItemType() { return _itemType; }
	void SetUsed(bool used) { _isUsed = used; };

private:
	ItemType _itemType;
	vector<HBRUSH> _brushes;
	bool _isUsed = false;
};


