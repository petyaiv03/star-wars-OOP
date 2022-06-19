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

///
void Galaxy::add_planet(String &planet_name)
{
	Planet planet(planet_name);
	Planet* array_ = new Planet[size + 1];
	for (int i = 0; i < size - 1; i++)
	{
		array_[i] = planets[i];//ot visual studio e :D
	}
	array_[size - 1] = planet;
	size++;
	delete [] planets;
	planets = array_;
}

void Galaxy::create_jedi(String &planet_name, String &jedi_name, JediRank &jedi_rank, int jedi_age, String &saber_color, double jedi_strength)
{
	Jedi jedi(jedi_name, jedi_rank, jedi_age, saber_color, jedi_strength);

	int planet_index;
	planet_index = get_index(planet_name);
	
	int sizeOfCurrentArray = planets[planet_index].getAmountOfJedi();

	Jedi* array_ = new Jedi[sizeOfCurrentArray + 1];
	for (int i = 0; i < size - 1; i++)
	{
		array_[i] = planets[planet_index].getJediOnPlanet()[i];
	}

	array_[sizeOfCurrentArray - 1] = jedi;
	sizeOfCurrentArray++;
	delete[] planets[planet_index].getJediOnPlanet();
	planets[planet_index].setJediOnPlanet(array_);
}

void Galaxy::remove_jedi(String& jedi_name, String& planet_name)
{
	int planet_index = get_index(planet_name);
	int sizeOfCurrentArray = planets[planet_index].getAmountOfJedi();

	--sizeOfCurrentArray;
	for (int i = planet_index; i < sizeOfCurrentArray; i++)
	{
		planets[planet_index].getJediOnPlanet()[i] = planets[planet_index].getJediOnPlanet()[i + 1];
	}
}

void Galaxy::promote_jedi(String& jedi_name, double multiplier)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < planets[i].getAmountOfJedi(); j++)
		{
			if (strcmp(planets[i].getJediOnPlanet()[j].getName().str(), jedi_name.str()) == 0)
			{
				planets[i].getJediOnPlanet()[j].setPower((1+multiplier) * (planets[i].getJediOnPlanet()[j].getPower()));
				if (planets[i].getJediOnPlanet()[j].getRank() != GRAND_MASTER)
				{
					planets[i].getJediOnPlanet()[j].setRank((JediRank)((int) planets[i].getJediOnPlanet()[j].getRank() + 1));
				}
				else
				{
					std::cout << "There isn't higher rank.\n";
				}
			}
		}
	}
}

void Galaxy::demote_jedi(String& jedi_name, double multiplier)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < planets[i].getAmountOfJedi(); j++)
		{
			if (strcmp(planets[i].getJediOnPlanet()[j].getName().str(), jedi_name.str()) == 0)
			{
				planets[i].getJediOnPlanet()[j].setPower((1 - multiplier) * (planets[i].getJediOnPlanet()[j].getPower()));
				if (planets[i].getJediOnPlanet()[j].getRank() != YOUNGLING)
				{
					planets[i].getJediOnPlanet()[j].setRank((JediRank)((int)planets[i].getJediOnPlanet()[j].getRank() - 1));
				}
				else
				{
					std::cout << "There isn't lower rank.\n";
				}
			}
		}
	}
}

void Galaxy::get_strongest_jedi(String& planet_name)
{
}

void Galaxy::get_most_used_saber_colour(String& planet_name)
{
}

void Galaxy::printJedi(String& jedi_name)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < planets[i].getAmountOfJedi(); j++)
		{
			if (strcmp(planets[i].getJediOnPlanet()[j].getName().str(), jedi_name.str()) == 0)
			{
				std::cout << planets[i].getJediOnPlanet()[j] << "Planet:" << planets[i].getName();
			}
		}
	}
}

///gets the index of the planet that is entered as a parameter and returns it as integer
int Galaxy::get_index(String& planet_name)
{
	int planet_index = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(planets[i].getName().str(), planet_name.str()) == 0)
		{
			planet_index = i;
		}
	}
	return planet_index;
}

