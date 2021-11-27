/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "Enemies/AbstractEnemyNPC.h"
#include "Enemies/ArcherEnemy.h"
#include "Enemies/MeleeEnemy.h"
#include "Enemies/GunnerEnemy.h"
#include <iostream>

using std::cout;
using std::endl;

class EnemyFactory
{
public:
	EnemyFactory()
	{
		//cout << "DEBUG : EnemyFactory constructed successfully" << endl; //debugging text, uncomment to see successful enemyFactory creations
	}
	virtual ~EnemyFactory() {};

	AbstractEnemyNPC *CreateEnemy(std::string fn, std::string theType); //create enemy method to generate an enemy from the various implemented enemies
	

};
