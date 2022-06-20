#pragma once
#include "string.h"

enum class JediRank
{
	YOUNGLING = 0,
	INITIATE = 1,
	PADAWAN = 2, 
	KNIGHT_ASPIRANT = 3, 
	KNIGHT = 4, 
	MASTER = 5, 
	BATTLE_MASTER = 6,
	GRAND_MASTER = 7
};

class Jedi
{
private:
	String name;
	JediRank rank;
	int age;
	String lightsaber_colour;
	double power;
public:
	static const char* JEDI_RANKS[]; 
	Jedi();
	Jedi(const String& _name, JediRank _rank, int _age,const String& _lightsaber_colour, double _power);
	String getName() const;
	JediRank getRank() const;
	void setRank(JediRank _rank);
	int getAge() const;
	String getColour() const;
	double getPower() const;
	void setPower(double _power);
	friend std::istream& operator >> (std::istream& in, Jedi& jedi);
	friend std::ostream& operator << (std::ostream& out, const Jedi& jedi);
};