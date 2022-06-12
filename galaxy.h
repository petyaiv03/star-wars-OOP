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
};