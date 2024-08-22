#pragma once
class HobGoblin : public Monster
{
public:
	HobGoblin(string name, int hp, int mp, int attack);
	virtual ~HobGoblin();

	void AggroAttack(vector<Creature*> players);

private:

};

