#pragma once
#include "string.h"
#include "jedi.h"

class Planet {
private:
	String planetName;
	Jedi* jediOnPlanet;
	int amountOfJedi;
public:
	Planet();
	Planet(const Planet& other);
	Planet& operator=(const Planet& other);
	~Planet();
private:
	void copy(const Planet& other);
	void clear();
};