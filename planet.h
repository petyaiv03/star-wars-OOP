#pragma once
#include "string.h"
#include "jedi.h"

class Planet {
private:
	String planetName;
	Jedi* jediOnPlanet;
	int amountOfJedi;
public:
	Planet(String planetName = "");
	Planet(const Planet& other);
	Planet& operator=(const Planet& other);
	~Planet();
	String getName() const;
	Jedi* getJediOnPlanet() const;
	void setJediOnPlanet(Jedi* _array);
	int getAmountOfJedi() const;
private:
	void copy(const Planet& other);
	void clear();
};