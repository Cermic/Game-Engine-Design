/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "SupplierFactory.h"

AbstractSupplier * SupplierFactory::CreateNPC(char * fn, char * theType)
{
	//cout << " Debug: SupplierFactory: CreateNPC()" << endl; //debugging text, uncomment to see successful SupplierFactory: CreateNPC() calls

	//check the type passed in, and return the relevant supplier
	if (theType == "resource")
		return new ResourceSupplier(fn, theType);
	else if (theType == "weapon")
		return new WeaponMerchant(fn, theType);
	else
	{
		//cout << "SUPPLIER NOT CREATED CORRECLTY @ AbstractSupplier * SupplierFactory::CreateNPC(char * fn, char * theType)" << endl; //debugging text
		return nullptr;
	}
}