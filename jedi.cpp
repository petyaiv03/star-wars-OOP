#include "jedi.h"

Jedi::Jedi()
{
	name = nullptr;
	rang = nullptr;
	age = 0;
	lightsaber_colour = nullptr;
	power = 0;
}

Jedi::Jedi(String _name, String _rang, int _age, String _lightsaber_colour, double _power)
{
	name = _name;
	rang = _rang;
	age = _age;
	lightsaber_colour = _lightsaber_colour;
	power = _power;
}

String Jedi::getName() const
{
	return name;
}

String Jedi::getRang() const
{
	return rang;
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
	in >> jedi.rang;
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
	out << jedi.rang;
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
