#pragma once
#include "string.h"
#include "jedi.h"

class Planet {
private:
	String planetName;
	Jedi* jediOnPlanet;
	int amountOfJedi;
public:
	//Planet(String planetName = "");
	Planet();
	Planet(const Planet& other);
	Planet& operator=(const Planet& other);
	~Planet();
	String getName() const;
	void setName(const String& _planetName);
	Jedi* getJediOnPlanet() const;
	void setJediOnPlanet(Jedi* _array);
	int getAmountOfJedi() const;

	void serializePlanet(std::ofstream& out) const;
	void deserializePlanet(std::ifstream& in);
private:
	void copy(const Planet& other);
	void clear();
};