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

void Galaxy::add_planet(String &planet_name)
{
	Planet planet(planet_name);
	Planet* array_ = new Planet[size + 1];
	for (int i = 0; i < size - 1; i++)
	{
		array_[i] = planets[i];//ot kompilatora e :D
	}
	array_[size - 1] = planet;
	size++;
	delete [] planets;
	planets = array_;
}

void Galaxy::create_jedi(String &planet_name, String &jedi_name, String &jedi_rank, int jedi_age, String &saber_color, double jedi_strength)
{
	Jedi jedi(jedi_name, jedi_rank, jedi_age, saber_color, jedi_strength);
	//gets index you can do it as function ot method---
	int planet_index;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(planets[i].getName().str(), planet_name.str()) == 0)
		{
			planet_index = i;
		}
	}
	//---
	/*Jedi* array_ = new Jedi[ + 1];
	for (int i = 0; i < size - 1; i++)
	{
		array_[i] = planets[i];
	}
	array_[size - 1] = planet;
	size++;
	delete[] planets;
	planets = array_;*/
}
