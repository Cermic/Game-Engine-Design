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


class AbstractEnemyNPC : public AbstractNPC //partially abstract class to provide further properties for enemy NPC types in the game
{
public:
	AbstractEnemyNPC(char *fn, char *theType) : AbstractNPC(fn, theType) {} //constructor follows abstractNPC constructor
	virtual ~AbstractEnemyNPC() {};

	//necessary getters and setters
	float getHP() { return health; }
	virtual float getDamage() = 0;
	void setHP(float h) { health = h; };

	virtual void attack() = 0; //attack method, virtual to allow different impementations for each enemy

protected:
	//protected properties that each enemy will have
	float health = 100;
	float damage;
};
