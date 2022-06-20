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
	int getSize() const;
	void add_planet(const const String &planet_name);
	void create_jedi(const String &planet_name, const String &jedi_name, JediRank &jedi_rank, int jedi_age, const String &saber_color, double jedi_strength);
	void remove_jedi(const String &jedi_name, const String &planet_name);
	void promote_jedi(const String &jedi_name, double multiplier);
	void demote_jedi(const String &jedi_name, double multiplier);
	void get_strongest_jedi(const String &planet_name);
	void get_youngest_jedi(const String &planet_name, JediRank &jedi_rank);
	void get_most_used_saber_colour(const String &planet_name, JediRank &jedi_rank);
	void get_most_used_saber_colour_(const String &planet_name);
	void print_planet(const String &planet_name);
	void print_jedi(const String &jedi_name);

	void serializeGalaxy(std::ofstream& out) const;
	void deserializeGalaxy(std::ifstream& in);
	
	void plus (const String &planet_name1, const String &planet_name2);

	int get_index(const String& planet_name);

};