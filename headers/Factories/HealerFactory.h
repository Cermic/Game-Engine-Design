/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "FriendlyNPCs/Healer/AbstractHealer.h"
#include "FriendlyNPCs/Healer/Medic.h"
#include <iostream>

using std::cout;
using std::endl;

class HealerFactory
{
public:
	HealerFactory()
	{
		//cout << "DEBUG : HealerFactory constructed successfully" << endl; //debugging text, uncomment to see successful HealerFactory creations
	}
	virtual ~HealerFactory() {};

	AbstractHealer *CreateNPC(char *fn, char *theType); //create NPC method to generate a healer from the various implemented healers (only one implemented at present)

};
