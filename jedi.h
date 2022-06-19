#pragma once
#include "string.h"

enum JediRank
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

const char* JEDI_RANKS[] = {"YOUNGLING", "INITIATE" ,"PADAWAN", "KNIGHT_ASPIRANT", "KNIGHT", "MASTER", "BATTLE_MASTER", "GRAND_MASTER"};

class Jedi
{
private:
	String name;
	String rank;
	int age;
	String lightsaber_colour;
	double power;
public:
	Jedi();
	Jedi(String _name, String _rank, int _age, String _lightsaber_colour, double _power);
	String getName() const;
	String getRank() const;
	int getAge() const;
	String getColour() const;
	double getPower() const;
	friend std::istream& operator >> (std::istream& in, Jedi& jedi);
	friend std::ostream& operator << (std::ostream& out, const Jedi& jedi);
};