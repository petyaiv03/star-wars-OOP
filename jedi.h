#pragma once
#include "string.h"

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