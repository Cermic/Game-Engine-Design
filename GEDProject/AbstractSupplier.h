/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "AbstractNPC.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class AbstractSupplier : public AbstractNPC //partially abstract class to provide further properties for supplier NPC types in the game
{
public:
	AbstractSupplier(char *fn, char *theType) : AbstractNPC(fn, theType) { money = 500; } //constructor follows abstractNPC constructor
	virtual ~AbstractSupplier() {};
	virtual string getInventory() = 0; //virtual get to allow implementation in specific suppliers
	void setInventory(string s, int pos) { inventory[pos] = s; }; //set inventory slot at pos(0 or 1) to the passed in string
	float getMoney() { return money; }
protected:
	string inventory[2]; //must have a defined size to allow resource/weapon merchants to inherit
	float money;
};
