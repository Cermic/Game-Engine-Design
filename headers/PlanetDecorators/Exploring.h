#pragma once
#include <iostream>
#include "PlanetDecorator.h"

using std::cout;

class Exploring : public PlanetDecorator {
public:
	Exploring(AbstractPlanet *p) : PlanetDecorator(p) { }

	void render();
	float getMovementSpeed() { return PlanetDecorator::getMovementSpeed(); }
	~Exploring() {}
private:
};