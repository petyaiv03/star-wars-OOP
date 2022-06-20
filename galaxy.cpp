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
				if (planets[i].getJediOnPlanet()[j].getRank() != JediRank :: GRAND_MASTER)
				{
					planets[i].getJediOnPlanet()[j].setRank((JediRank)((int) planets[i].getJediOnPlanet()[j].getRank() + 1));
				}
				else
				{
					std::cout << "There isn't higher rank. Jedi remains the same rank. \n";
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
				if (planets[i].getJediOnPlanet()[j].getRank() != JediRank::YOUNGLING)
				{
					planets[i].getJediOnPlanet()[j].setRank((JediRank)((int)planets[i].getJediOnPlanet()[j].getRank() - 1));
				}
				else
				{
					std::cout << "There isn't lower rank. Jedi remains the same rank. \n";
				}
			}
		}
	}
}

void Galaxy::get_strongest_jedi(String& planet_name)
{
	int planet_index = get_index(planet_name);
	double max_power = -1;
	int max_power_index = -1;
	for (int i = 0; i < planets[planet_index].getAmountOfJedi(); i++)
	{
		if (max_power < planets[planet_index].getJediOnPlanet()[i].getPower())
		{
			max_power = planets[planet_index].getJediOnPlanet()[i].getPower();
			max_power_index = i;
		}
	}
	std::cout << planets[planet_index].getJediOnPlanet()[max_power_index];
}

void Galaxy::get_youngest_jedi(String& planet_name, JediRank& jedi_rank)
{
	int planet_index = get_index(planet_name);
	int temp_size = 0;

	for (int i = 0; i < planets[planet_index].getAmountOfJedi(); i++)
	{
		if (planets[planet_index].getJediOnPlanet()[i].getRank() == jedi_rank)
		{
			temp_size++;
		}
	}

	Jedi* temp = new Jedi[temp_size];
	for (int i = 0, j = 0; j < temp_size ; i++, j++)
	{ 
		if (planets[planet_index].getJediOnPlanet()[i].getRank() == jedi_rank)
		{
			temp[j] = planets[planet_index].getJediOnPlanet()[i];
		}
	}

	if (temp_size > 0)
	{
		int min_index = 0;
		for (int i = 0; i < temp_size; i++)
		{
			min_index = i;
			for (int j = i + 1; j < temp_size; j++)
			{
				if (planets[planet_index].getJediOnPlanet()[j].getAge() < planets[planet_index].getJediOnPlanet()[i].getAge())
				{
					min_index = j;
				}
				if (min_index != i)
				{
					Jedi jedi_t;
					jedi_t = temp[i];
					temp[i] = temp[min_index];
					temp[min_index] = jedi_t;
				}
			}
		}
		std::cout << "This is the youngest Jedi of this rank: \n" << temp[0] << std::endl;
	}
	else
	{
		std::cout << "A Jedi with this rank doesn't exist. \n";
	}

	delete[] temp;
}

void Galaxy::get_most_used_saber_colour(String& planet_name, JediRank& jedi_rank)
{
	int planet_index = get_index(planet_name);
	int temp_size = 0;

	//gets amount of jedi with chosen rank -> can be done as separate method or function

	for (int i = 0; i < planets[planet_index].getAmountOfJedi(); i++)
	{
		if (planets[planet_index].getJediOnPlanet()[i].getRank() == jedi_rank)
		{
			temp_size++;
		}
	}

	//creates new array and fills it with the jedi with chosen rank -> can be done as separate method or function

	Jedi* temp = new Jedi[temp_size];
	for (int i = 0, j = 0; j < temp_size; i++, j++)
	{
		if (planets[planet_index].getJediOnPlanet()[i].getRank() == jedi_rank)
		{
			temp[j] = planets[planet_index].getJediOnPlanet()[i];
		}
	}

	//gets the index of the most used colour -> can be done as separate method or function

	int maxcount = 0;
	int most_used_clr_index = 0;
	for (int i = 0; i < temp_size; i++)
	{
		int count = 0;
		for (int j = 0; j < temp_size; j++)
		{
			if (strcmp(temp[i].getColour().str(),temp[j].getColour().str()) == 0)
				count++;
		}

		if (count > maxcount)
		{
			maxcount = count;
			temp[most_used_clr_index] = temp[i];
		}
	}

	std::cout << "Most used by chosen rank saber colour on the planet is " << temp[most_used_clr_index].getColour() << ".\n";

	delete[] temp;
}

void Galaxy::get_most_used_saber_colour(String& planet_name)
{

}

void Galaxy::printPlanet(String& planet_name)
{
	int planet_index = get_index(planet_name);
	int min_index;
	
	//selection sort to sort the jedi A - Z -> can be done as separate method or function

	for (int i = 0; i < planets[planet_index].getAmountOfJedi(); i++)
	{
		min_index = i;
		for (int j = i + 1; j < planets[planet_index].getAmountOfJedi(); j++)
		{
			if (strcmp(planets[planet_index].getJediOnPlanet()[j].getName().str(), planets[planet_index].getJediOnPlanet()[min_index].getName().str()) < 0)
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Jedi temp;
			temp = planets[planet_index].getJediOnPlanet()[i];
			planets[planet_index].getJediOnPlanet()[i] = planets[planet_index].getJediOnPlanet()[min_index];
			planets[planet_index].getJediOnPlanet()[min_index] = temp;
		}
	}

	//bubble sort to sort the ranks without messing up the alphabetical order -> can be done as separate method or function
	
	for (int i = 0; i < planets[planet_index].getAmountOfJedi() - 1; i++)
	{
		for (int j = 0; j < planets[planet_index].getAmountOfJedi() - i - 1; j++)
		{
			if (planets[planet_index].getJediOnPlanet()[j].getRank() > planets[planet_index].getJediOnPlanet()[j + 1].getRank())
			{
				Jedi temp;
				temp = planets[planet_index].getJediOnPlanet()[i];
				planets[planet_index].getJediOnPlanet()[i] = planets[planet_index].getJediOnPlanet()[min_index];
				planets[planet_index].getJediOnPlanet()[min_index] = temp;
			}
		}
	}

	std::cout <<"The jedi on planet " << planet_name << " are :\n" << std::endl;
	for (int i = 0; i < planets[planet_index].getAmountOfJedi(); i++)
	{
		std::cout << planets[planet_index].getJediOnPlanet()[i] << std::endl;
	}
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

