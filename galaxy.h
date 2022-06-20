#pragma once
#include "planet.h"
#include "string.h"

///class that has array of planets and size of the array as members
class Galaxy {
private:
	Planet* planets;
	int size;
public:
	///big 4
	Galaxy();
	Galaxy(const Galaxy& other);
	Galaxy& operator = (const Galaxy& other);
	~Galaxy();
private:
	void copy(const Galaxy& other);
	void clear();
public:
	///getter for size, returns integer type size
	int getSize() const;

	///method that adds planet(element) to the array of planets
	void add_planet(const String &planet_name);

	///method that creates jedi and adds it to the array of jedi in chosen by the user planet
	void create_jedi(const String &planet_name, const String &jedi_name, JediRank &jedi_rank, int jedi_age, const String &saber_color, double jedi_strength);

	///method with parameters string jedi name and string planet name that removes jedi from chosen from the user planet
	void remove_jedi(const String &jedi_name, const String &planet_name);

	///method with parameters jedi name and multiplier that promotes jedi to the next rank
	void promote_jedi(const String &jedi_name, double multiplier);

	///method with parameters jedi name and multiplier that demotes jedi to the lower rank
	void demote_jedi(const String &jedi_name, double multiplier);

	///method that gets strongest jedi within chosen planet and prints it
	void get_strongest_jedi(const String &planet_name);

	///method that gets youngest jedi with parameters planet name and jedi rank and sorts alphabeticaly if more than one
	void get_youngest_jedi(const String &planet_name, JediRank &jedi_rank);

	///method that gets most used saber colour in chosen planet by chosen rank
	void get_most_used_saber_colour(const String &planet_name, JediRank &jedi_rank);

	//TODO
	void get_most_used_saber_colour_(const String &planet_name);

	///method that prints out all jedi that live on chosen planet alphabetically and rankwise
	void print_planet(const String &planet_name);

	///prints jedi with all of its parameters
	void print_jedi(const String &jedi_name);

	
	void serializeGalaxy(std::ofstream& out) const;
	void deserializeGalaxy(std::ifstream& in);
	
	///method that adds two arrays of jedi from diff planets and sorts them alphabetically
	void plus (const String &planet_name1, const String &planet_name2);

	///returns int (index) from string input ->planet
	int get_index(const String& planet_name);

};