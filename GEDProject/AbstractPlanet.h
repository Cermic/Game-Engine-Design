/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include <iostream>

class AbstractPlanet //abstract planet class for necessary virtual methods
{
public:
	virtual void render() = 0; //render method to show the type of planet
	virtual float getMovementSpeed() = 0; //getMovement speed to return movement modifier
	virtual ~AbstractPlanet() {}
};
