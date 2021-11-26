/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "random.h"
#include "SupplierFactory.h"
#include "EnemyFactory.h"
#include "HealerFactory.h"
#include <iostream>

class NPCGenerator
{
	//taking no parameters is for random generation, taking an int allows specific generation
public:
	AbstractSupplier* createSupplier(); 
	AbstractSupplier * createSupplier(int choice);

	//healers not entirely necessary as the program stands, but would be useful in future if more types of healer are created
	AbstractHealer * createHealer(int choice);

	AbstractEnemyNPC* createEnemy();
	AbstractEnemyNPC * createEnemy(int choice);

	//storage for outputs to other classes
	AbstractSupplier* supplier = nullptr;
	AbstractHealer* healer = nullptr;
	AbstractEnemyNPC* enemy = nullptr;

	virtual ~NPCGenerator() {};
private:
	//private factories to be used to generate npcs
	SupplierFactory supplierNPCs;
	EnemyFactory enemyNPCs;
	HealerFactory healerNPCs;
};