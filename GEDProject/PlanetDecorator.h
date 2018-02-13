/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "AbstractPlanet.h"
#include <iostream>

class PlanetDecorator : public AbstractPlanet //planet decorators also require the virtual properties in abstractPlanet to add to them
{
public:
	PlanetDecorator(AbstractPlanet *p) { planet = p; } //planerDecorator takes a planet to be "decorated"

	void render() { planet->render(); } //delegate rendering to the planets render method
	float getMovementSpeed() { return planet->getMovementSpeed(); } //delegate to the planets method

	virtual ~PlanetDecorator() { delete (this->planet); }
private:
	AbstractPlanet * planet; //planet to be "decorated"
};