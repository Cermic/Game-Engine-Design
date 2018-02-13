/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include <iostream>
#include "PlanetDecorator.h"

using std::cout;

class Arid : public PlanetDecorator {
public:
	Arid(AbstractPlanet *p) : PlanetDecorator(p) { } //take planet to be "decorated"

	void render(); //render method to output the decorator type
	float getMovementSpeed() { return PlanetDecorator::getMovementSpeed() * movementModifier; } //get modified movementSpeed
	~Arid() {}
private:
	const float movementModifier = 0.8f;
};