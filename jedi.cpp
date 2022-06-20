#include "jedi.h"

const char* Jedi::JEDI_RANKS[] = {"YOUNGLING", "INITIATE" ,"PADAWAN", "KNIGHT_ASPIRANT", "KNIGHT", "MASTER", "BATTLE_MASTER", "GRAND_MASTER"};

Jedi::Jedi()
{
	name = nullptr;
	rank = JediRank::YOUNGLING;
	age = 0;
	lightsaber_colour = nullptr;
	power = 0;
}

Jedi::Jedi(const String& _name,JediRank _rank, int _age,const String& _lightsaber_colour, double _power)
{
	name = _name;
	rank = _rank;
	age = _age;
	lightsaber_colour = _lightsaber_colour;
	power = _power;
}

Jedi::Jedi(std::ifstream& in)
{
	name.deserialize(in);
	in.read((char*)&rank, sizeof(rank));
	in.read((char*)&age, sizeof(age));
	lightsaber_colour.deserialize(in);
	in.read((char*)&power, sizeof(power));
}

void Jedi::jediSerialize(std::ofstream& out) const
{
	int length_name = name.getSize() + 1;
	out.write((const char*)&length_name, sizeof(length_name));
	out.write(name.str(), length_name);

	out.write((const char*)&rank, sizeof(rank));

	out.write((const char*)&age, sizeof(age));

	int length_color = name.getSize() + 1;
	out.write((const char*)&length_color, sizeof(length_color));
	out.write(name.str(), length_color);

	out.write((const char*)&power, sizeof(power));
}

String Jedi::getName() const
{
	return name;
}

JediRank Jedi::getRank() const
{
	return rank;
}

void Jedi::setRank(JediRank _rank)
{
	rank = _rank;
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

void Jedi::setPower(double _power)
{
	power = _power;
}

std::istream& operator>>(std::istream& in, Jedi& jedi)
{
	in >> jedi.name;
	String inputRank;
	in >> inputRank;
	for (int i = 0; i <=(int) JediRank::GRAND_MASTER; i++)
	{
		if (strcmp(Jedi::JEDI_RANKS[i], inputRank.str()) == 0)
		{
			jedi.rank = (JediRank) i;
		}
	}
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
	out << Jedi::JEDI_RANKS[(int)jedi.rank];
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
