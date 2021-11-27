#pragma once
#include <iostream>
#include "PlanetDecorator.h"

using std::cout;

class Fighting : public PlanetDecorator {
public:
	Fighting(AbstractPlanet *p) : PlanetDecorator(p) { }

	void render();
	float getMovementSpeed() { return PlanetDecorator::getMovementSpeed(); }
	~Fighting() {}
private:
};