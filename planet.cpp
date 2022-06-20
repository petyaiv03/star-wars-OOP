#include "planet.h"

//Planet::Planet(String planetName) : planetName(planetName), jediOnPlanet(nullptr), amountOfJedi(0) {}

Planet::Planet()
{
	planetName = nullptr;
	jediOnPlanet = nullptr;
	amountOfJedi = 0;
}

Planet::Planet(const Planet& other)
{
	copy(other);
}

Planet& Planet::operator=(const Planet& other)
{
	if (this != &other)
	{
		clear();
		this->copy(other);
	}
	return *this;
}

Planet::~Planet()
{
	clear();
}

String Planet::getName() const
{
	return planetName;
}

void Planet::setName(const String& _planetName)
{
	planetName = _planetName;
}

Jedi* Planet::getJediOnPlanet() const
{
	return jediOnPlanet;
}

void Planet::setJediOnPlanet(Jedi* _array)
{
	jediOnPlanet = _array;
}

int Planet::getAmountOfJedi() const
{
	return amountOfJedi;
}

void Planet::serializePlanet(std::ofstream& out) const
{
	int length_name = planetName.getSize() + 1;
	out.write((const char*)&length_name, sizeof(length_name));
	out.write(planetName.str(), length_name);

	out.write((const char*)&amountOfJedi, sizeof(amountOfJedi));
	for (int i = 0; i < amountOfJedi; i++)
	{
		jediOnPlanet[i].jediSerialize(out);
	}
}

void Planet::deserializePlanet(std::ifstream& in)
{
	clear();
	planetName.deserialize(in);
	in.read((char*)&amountOfJedi, sizeof(amountOfJedi));
	if (amountOfJedi > 0)
	{
		jediOnPlanet = new Jedi[amountOfJedi];
	}
	for (int i = 0; i < amountOfJedi; i++)
	{
		jediOnPlanet[i] = Jedi(in);
	}
}

void Planet::copy(const Planet& other)
{
	planetName = other.planetName;
	if (other.amountOfJedi > 0)
	{
		jediOnPlanet = new Jedi[other.amountOfJedi];
		for (int i = 0; i < other.amountOfJedi; ++i)
		{
			jediOnPlanet[i] = other.jediOnPlanet[i];
		}
	}
	amountOfJedi = other.amountOfJedi;
}

void Planet::clear()
{
	delete []jediOnPlanet;
}
