/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "Factories/HealerFactory.h"

AbstractHealer * HealerFactory::CreateNPC(char * fn, char * theType)
{
	//cout << " Debug: HealerFactory: CreateNPC()" << endl; //debugging text, uncomment to see successful HealerFactory: CreateNPC() calls

	//check the type passed in, and return the relevant healer
	if (theType == "medic")
		return new Medic(fn, theType);
	else
	{
		//cout << "HEALER NOT CREATED CORRECLTY @ AbstractHealer * HealerFactory::CreateNPC(char * fn, char * theType)" << endl;  //debugging text
		return nullptr;
	}
}