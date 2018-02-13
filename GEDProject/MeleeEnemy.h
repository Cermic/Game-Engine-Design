/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "AbstractEnemyNPC.h"
#include <iostream>

using std::cout;
using std::endl;

class MeleeEnemy : public AbstractEnemyNPC
{
public:
	MeleeEnemy(char *fn, char *theType) : AbstractEnemyNPC(fn, theType) {} //constructor follows abstractEnemyNPC constructor
	virtual ~MeleeEnemy() {};
	void attack() { cout << name << " attacks player, deals " << damage << " damage." << endl; }//attack method to show damage output 
	float getDamage() { return damage; } //for other calls to obtain enemy damage
private:
	float damage = 5;  //defined damage property for the type of enemy
};