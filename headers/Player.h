/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once
#include "PlayerState.h"
#include "States/BattleState.h"
#include "States/ExplorationState.h"
#include "States/IdleState.h"
#include "States/LootState.h"
#include "States/NPCConverseState.h"
#include "States/TravellingState.h"
#include "States/GameEndState.h"
#include "Utilities/random.h"
#include "Subject.h"
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::swap;

class Player: public Subject // Player inherits from Subject. This allows player to notify the Observers of updates
{
private:
	PlayerState* current;
	PlayerState* idleState;
	PlayerState* travellingState;
	PlayerState* npcConverseState;
	PlayerState* explorationState;
	PlayerState* battleState;
	PlayerState* lootState;
	PlayerState* gameEndState;
	// a pointet to the different player states are declared
	float health=100;
	int energy=15;
	int damage=10;
	int money=100;
	int resources=3;
	int healthKits=3;
	int goods=3;
	string inventoryList[10];
	// initialisation of varibles for the player
public:
	Player();
	virtual ~Player()//virtual destructor
	{
		delete idleState; //deletes the following states
		delete travellingState;
		delete npcConverseState;
		delete explorationState;
		delete battleState;
		delete lootState;
		delete gameEndState;
	}

	void setCurrentState(PlayerState* state);// method that sets the current state to the passed in value
	PlayerState* getCurrentState(); 
	PlayerState* getIdleState();
	PlayerState* getTravellingState();
	PlayerState* getNPCConverseState();
	PlayerState* getExplorationState();
	PlayerState* getBattleState();
	PlayerState* getLootState();
	PlayerState* getGameEndState();
	// Accessors for the various states


	float getHealth() { return health; }
	int getEnergy()		{ return energy; }
	int getDamage()		{ return damage; }
	int getMoney()		{ return money; }
	int getResources()	{ return resources; }
	int getHealthKits() { return healthKits; }
	int getGoods() { return goods; }
	string getInventory();
	// accessors for the player's properties

	void setHealth(float heal);	
	void setEnergy(int energyloss); 
	void setDamage(int dam); 
	void setMoney(int mon); 
	void setDefaultInventory();
	void setInventory(string invString);
	void setHealthKits(int change);
	void setResources(int change);
	void setGoods(int change);
	// mutators for changing player stats


	void registerObserver(Observer * observer); // Adds a new Observer to the vector

	void removeObserver(Observer * observer); // Removes an Observer from the vector

	void notifyObserver();//Updates the Observers
};
