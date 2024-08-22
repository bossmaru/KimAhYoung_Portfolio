#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int mp, int attack);
	Knight(const Knight& other) : Player(other)
	{
		_stamina = other._stamina;
	}
	Knight& operator = (const Knight& other)
	{
		return *this;
	}

	virtual ~Knight();

	virtual void PrintInfo() override;
	virtual void PreAttack(Creature* other) override;
	virtual void Attack(Creature* other) override;
	virtual void GetExp(int amount) override;

private:
	int _stamina;
};

