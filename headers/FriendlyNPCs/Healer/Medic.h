/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "AbstractHealer.h"
#include <iostream>

using std::cout;
using std::endl;

class Medic : public AbstractHealer //medic class is a healer type
{
public:
	Medic(char *fn, char *theType) : AbstractHealer(fn, theType) {} //constructor follows abstractHealer constructor
	virtual ~Medic() {};

	void healPlayer(); //healPlayer emthod to output message indicating player has been healed
};