/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include <iostream>
#include "AbstractPlanet.h"

using std::cout;
using std::endl;

class Planet : public AbstractPlanet //basic planet provides some base properties and outputs
{
public:
	Planet();
	void render() { cout << " Planet." << endl; } //base output, should appear at the end of each render
	float getMovementSpeed() {return baseMovementSpeed;}

	~Planet() { cout << "Deleting Planet Object" << endl; };
private:
	float baseMovementSpeed = 10; //base movement speed for each planet, for modifying the amount of energy it requires to make a move when exploring a planet
};