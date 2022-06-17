#include "planet.h"

Planet::Planet(String planetName) : planetName(planetName), jediOnPlanet(nullptr), amountOfJedi(0) {}

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

void Planet::copy(const Planet& other)
{
	planetName = other.planetName;
	jediOnPlanet = new Jedi[other.amountOfJedi];
	for (int i = 0; i < amountOfJedi; ++i)
	{
		jediOnPlanet[i] = other.jediOnPlanet[i];
	}
	amountOfJedi = other.amountOfJedi;
}

void Planet::clear()
{
	delete[] jediOnPlanet;
}
