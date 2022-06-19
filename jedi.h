#pragma once
#include "string.h"

enum class JediRank
{
	YOUNGLING,
	INITIATE,
	PADAWAN, 
	KNIGHT_ASPIRANT, 
	KNIGHT, 
	MASTER, 
	BATTLE_MASTER,
	GRAND_MASTER
};

class Jedi
{
private:
	static const char* JEDI_RANKS[]; 
	String name;
	JediRank rank;
	int age;
	String lightsaber_colour;
	double power;
public:
	Jedi();
	Jedi(String _name, JediRank _rank, int _age, String _lightsaber_colour, double _power);
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