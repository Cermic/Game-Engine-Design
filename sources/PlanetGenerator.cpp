/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "PlanetGenerator.h"

AbstractPlanet* PlanetGenerator::generatePlanet()
{
	bool generated = false;
	int choice = (int)rnd(1, 7); //generate a random int to pick a planet from below
	while (!generated)
	{
		switch (choice)
		{
			//planet is generated to be the same as in the list below i.e. new Hub(new Planet) will generate a Hub Planet, new Arid(new Flat(new Planet)) will generate an Arid Flat Planet.
			//store the result in planet
		case 1:
			planet = new Hub(new Planet);
			generated = true;
			break;
		case 2:
			planet = new Arid(new Flat(new Planet));
			generated = true;
			break;
		case 3:
			planet = new Tropical(new Marine(new Planet));
			generated = true;
			break;
		case 4:
			planet = new Tropical(new Rough(new Planet));
			generated = true;
			break;
		case 5:
			planet = new Polar(new Flat(new Planet));
			generated = true;
			break;
		case 6:
			planet = new Polar(new Flat(new Planet));
			generated = true;
			break;
		case 7:
			planet = new Arid(new Rough(new Planet));
			generated = true;
			break;
		default:
			cout << "PLANET NOT CORRECTLY GENERATED" << endl; //default case in case of any errors, output error message
			generated = true;
			break;
		}
	}
	return planet;
}

AbstractPlanet* PlanetGenerator::generatePlanet(int i)
{
	bool generated = false;
	int choice = i; //set choice to passed in value
	while (!generated)
	{
		switch (choice)
		{
			//planet is generated to be the same as in the list below i.e. new Hub(new Planet) will generate a Hub Planet, new Arid(new Flat(new Planet)) will generate an Arid Flat Planet.
			//store the result in planet
		case 1:
			planet = new Hub(new Planet);
			generated = true;
			break;
		case 2:
			planet = new Arid(new Flat(new Planet));
			generated = true;
			break;
		case 3:
			planet = new Tropical(new Marine(new Planet));
			generated = true;
			break;
		case 4:
			planet = new Tropical(new Rough(new Planet));
			generated = true;
			break;
		case 5:
			planet = new Polar(new Flat(new Planet));
			generated = true;
			break;
		case 6:
			planet = new Polar(new Flat(new Planet));
			generated = true;
			break;
		case 7:
			planet = new Arid(new Rough(new Planet));
			generated = true;
			break;
		default:
			cout << "PLANET NOT CORRECTLY GENERATED" << endl; //default case in case of any errors, output error message
			generated = true;
			break;
		}
	}
	return planet;
}
