/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "FriendlyNPCs/Supplier/ResourceSupplier.h"

ResourceSupplier::ResourceSupplier(char *fn, char *theType) : AbstractSupplier(fn, theType) //constructor follows abstractSupplier constructor
{
	//initialise inventory values
	inventory[0] = { "Ration" };
	inventory[1] = { "Health Kit" };
}

string ResourceSupplier::getInventory()
{
	//takes each value the string and adds them to a single string for output
	string inventoryString = "";
	for (int i =0; i<2; i++)
	{
		inventoryString += i + " : " + inventory[i] +"\n";
	}
	return inventoryString;
}
