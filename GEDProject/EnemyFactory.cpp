/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "EnemyFactory.h"

AbstractEnemyNPC * EnemyFactory::CreateEnemy(char * fn, char * theType)
{
	//cout << " Debug: EnemyFactory: CreateEnemy()" << endl; //debugging text, uncomment to see successful enemyFactory::createEnemy() calls

	//check the type passed in, and return the relevant enemy
	if (theType == "archer")
		return new ArcherEnemy(fn, theType);
	else if (theType == "melee")
		return new MeleeEnemy(fn, theType);
	else if (theType == "gun")
		return new GunnerEnemy(fn, theType);
	else
	{
		//cout << "ENEMY NOT CREATED CORRECLTY @ AbstractEnemyNPC * EnemyFactory::CreateEnemy(char * fn, char * theType)" << endl; //debugging text
		return nullptr;
	}
}
