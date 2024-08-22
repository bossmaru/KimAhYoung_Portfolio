#pragma once
class Goblin : public Monster
{
public:
	Goblin(string name, int hp, int mp, int attack);
	virtual ~Goblin();

	virtual void Attack(Player* other);
	void Clone(vector<Creature*>& monsters);
};

