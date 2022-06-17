#pragma once
#include "planet.h"
#include "string.h"
class Galaxy {
private:
	Planet* planets;
	int size;
public:
	Galaxy();
	Galaxy(const Galaxy& other);
	Galaxy& operator = (const Galaxy& other);
	~Galaxy();
private:
	void copy(const Galaxy& other);
	void clear();
public:
	void add_planet(String planet_name);
	void create_jedi(String planet_name, String jedi_name, String jedi_rank, int jedi_age, String saber_color, double jedi_strength);
	void remove_jedi(String jedi_name, String planet_name);
	void promote_jedi(String jedi_name, double multiplier);
	void demote_jedi(String jedi_name, double multiplier);
	void get_strongest_jedi(String planet_name);
	void get_youngest_jedi(String planet_name, String jedi_rank);
	void get_most_used_saber_colour(String planet_name, String jedi_rank);
	void get_most_used_saber_colour(String planet_name);
	void printPlanet(String planet_name);
	void printJedi(String jedi_name);
	Galaxy& operator + (const Galaxy& other);//should i overload for planet class?
};