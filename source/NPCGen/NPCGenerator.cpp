/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "NPCs/NPCGenerator.h"

AbstractHealer* NPCGenerator::createHealer(int choice) //creates a specific healer relating to the passed in integer
{
	bool generated = false;
	while (!generated)
	{
		switch (choice)
		{
		case 1:
			healer = healerNPCs.CreateNPC("Medic", "medic");  //calls the createNPC method of the healer factory, passing in values to create a medic, stores the value in healer
			generated = true;
			break;
		default:
			cout << "ERROR : HEALER NOT CORRECTLY GENERATED @ npcGen.createHealer(choice)" << endl; //output an error if healer isn't correctly generated
			generated = true;
			break;
		}
	}
	return healer;
}

AbstractSupplier* NPCGenerator::createSupplier()
{
	bool generated = false;
	int choice = (int)rnd(1, 3); //randomly generate an int to choose a supplier
	while (!generated)
	{
		switch (choice)
		{
		case 1:
			supplier = supplierNPCs.CreateNPC("Weapons Merchant", "weapon"); //generate a weapons merchant using the supplier factory and store in supplier
			generated = true;
			break;
		case 2:
			supplier = supplierNPCs.CreateNPC("Resource Merchant", "resource"); //generate a resource merchant using the supplier factory and store in supplier
			generated = true;
			break;
		default:
			cout << "ERROR : SUPPLIER NOT CORRECTLY GENERATED @ npcGen.createSupplier()" << endl; //output an error if supplier isn't correctly generated
			generated = true;
			break;
		}
	}
	return supplier;
}

AbstractSupplier* NPCGenerator::createSupplier(int choice)
{
	//generate a specific supplier by passing in the appropriate int for the enemy you need

	bool generated = false;
	while (!generated)
	{
		switch (choice)
		{
		case 1:
			supplier = supplierNPCs.CreateNPC("Weapons Merchant", "weapon"); //generate a weapons merchant using the supplier factory and store in supplier
			generated = true;
			break;
		case 2:
			supplier = supplierNPCs.CreateNPC("Resource Merchant", "resource"); //generate a resource merchant using the supplier factory and store in supplier
			generated = true;
			break;
		default:
			cout << "ERROR : SUPPLIER NOT CORRECTLY GENERATED @ npcGen.createSupplier(choice)" << endl; //output an error if supplier isn't correctly generated
			generated = true;
			break;
		}
	}
	return supplier;
}

AbstractEnemyNPC* NPCGenerator::createEnemy()
{
	bool generated = false;
	int choice = (int)rnd(1, 3); //randomly generate an int to choose an enemy
	while (!generated)
	{
		switch (choice)
		{
		case 1:
			enemy = enemyNPCs.CreateEnemy("Archer", "archer"); //generate an archer enemy using the enemy factory and store in enemy
			generated = true;
			break;
		case 2:
			enemy = enemyNPCs.CreateEnemy("Melee", "melee");  //generate a melee enemy using the enemy factory and store in enemy
			generated = true;
			break;
		case 3:
			enemy = enemyNPCs.CreateEnemy("Gunner", "gun"); //generate a gunner enemy using the enemy factory and store in enemy
			generated = true;
			break;
		default:
			cout << "ERROR : ENEMY NOT CORRECTLY GENERATED @ npcGen.createEnemy()" << endl; //output an error if enemy isn't correctly generated
			generated = true;
			break;
		}
	}
	return enemy;
}

AbstractEnemyNPC* NPCGenerator::createEnemy(int choice)
{
	//generate a specific enemy by passing in the appropriate int for the enemy you need

	bool generated = false;
	while (!generated)
	{
		switch (choice)
		{
		case 1:
			enemy = enemyNPCs.CreateEnemy("Archer", "archer"); //generate an archer enemy using the enemy factory and store in enemy
			generated = true;
			break;
		case 2:
			enemy = enemyNPCs.CreateEnemy("Melee", "melee");  //generate a melee enemy using the enemy factory and store in enemy
			generated = true;
			break;
		case 3:
			enemy = enemyNPCs.CreateEnemy("Gunner", "gun"); //generate a gunner enemy using the enemy factory and store in enemy
			generated = true;
			break;
		default:
			cout << "ERROR : ENEMY NOT CORRECTLY GENERATED @ npcGen.createEnemy(choice)" << endl; //output an error if enemy isn't correctly generated
			generated = true;
			break;
		}
	}
	return enemy;
}