#include "jedi.h"

Jedi::Jedi()
{
	name = nullptr;
	rank = nullptr;
	age = 0;
	lightsaber_colour = nullptr;
	power = 0;
}

Jedi::Jedi(String _name, String _rank, int _age, String _lightsaber_colour, double _power)
{
	name = _name;
	rank = _rank;
	age = _age;
	lightsaber_colour = _lightsaber_colour;
	power = _power;
}

String Jedi::getName() const
{
	return name;
}

String Jedi::getRank() const
{
	return rank;
}

int Jedi::getAge() const
{
	return age;
}

String Jedi::getColour() const
{
	return lightsaber_colour;
}

double Jedi::getPower() const
{
	return power;
}

std::istream& operator>>(std::istream& in, Jedi& jedi)
{
	in >> jedi.name;
	in >> jedi.rank;
	in >> jedi.age;
	in >> jedi.lightsaber_colour;
	in >> jedi.power;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Jedi& jedi)
{
	out << "Name: ";
	out << jedi.name;
	out << " ";
	
	out << "Rang: ";
	out << jedi.rank;
	out << " ";

	out << "Age: ";
	out << jedi.age;
	out << " ";

	out << "Lightsaber colour: ";
	out << jedi.lightsaber_colour;
	out << " ";

	out << "Power: ";
	out << jedi.power;
	out << " ";

	return out;
}
