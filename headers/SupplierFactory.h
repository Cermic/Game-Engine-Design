/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "AbstractSupplier.h"
#include "ResourceSupplier.h"
#include "WeaponMerchant.h"
#include <iostream>

using std::cout;
using std::endl;

class SupplierFactory
{
public:
	SupplierFactory()
	{
		//cout << "DEBUG : SupplierFactory constructed successfully" << endl; //debugging text, uncomment to see successful SupplierFactory creations
	}
	virtual ~SupplierFactory() {};

	AbstractSupplier *CreateNPC(char *fn, char *theType); //create NPC method to generate a supplier from the various implemented suppliers

};
