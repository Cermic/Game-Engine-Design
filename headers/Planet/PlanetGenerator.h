/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "Utilities/random.h"
#include "AbstractPlanet.h"
#include "PlanetDecorator.h"
#include "Planet.h"
#include "PlanetDecorators/Arid.h"
#include "PlanetDecorators/Flat.h"
#include "PlanetDecorators/Hub.h"
#include "PlanetDecorators/Marine.h"
#include "PlanetDecorators/Polar.h"
#include "PlanetDecorators/Rough.h"
#include "PlanetDecorators/Tropical.h"
#include <iostream>

class PlanetGenerator
{
public:
	AbstractPlanet* generatePlanet();
	AbstractPlanet* generatePlanet(int i);
	AbstractPlanet *planet;
};