/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "NPCs/AbstractNPC.h"
#include <iostream>

using std::cout;
using std::endl;

class AbstractHealer : public AbstractNPC //partially abstract class to provide further properties for healer NPC types in the game
{
public:
	AbstractHealer(char *fn, char *theType) : AbstractNPC(fn, theType) { money = 500; }  //constructor follows abstractNPC constructor, initialises money to 500
	virtual ~AbstractHealer() {};

	//required getters
	float getMoney() { return money; }

	virtual void healPlayer() = 0; //virtual method to allow healers to have different ways to heal player
private:
	float money; //money property for each healer
};
