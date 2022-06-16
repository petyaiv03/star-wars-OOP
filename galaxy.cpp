#include "galaxy.h"

Galaxy::Galaxy()
{
	planets = nullptr;
	size = 0;
}

Galaxy::Galaxy(const Galaxy& other)
{
	copy(other);
}

Galaxy& Galaxy::operator=(const Galaxy& other)
{
	if (this != &other)
	{
		clear();
		this->copy(other);
	}
	return *this;
}

Galaxy::~Galaxy()
{
	clear();
}

void Galaxy::copy(const Galaxy& other)
{
	size = other.size;
	planets = new Planet[other.size];
	for (int i = 0; i < size; ++i)
	{
		planets[i] = other.planets[i];
	}
}

void Galaxy::clear()
{
	delete[] planets;
}
