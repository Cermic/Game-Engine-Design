/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Player.h"

Player::Player()
{
	battleState = new BattleState();
	explorationState = new ExplorationState();
	idleState = new IdleState();
	lootState = new LootState();
	npcConverseState = new NPCConverseState();
	travellingState = new TravellingState();
	gameEndState = new GameEndState();
	// declaration of all the state objects that the player uses.

	current = idleState; // current state set to IdleState
	current->handle(this);
	// Passes the current object into the handle, in this case idleState.
}

void Player::setCurrentState(PlayerState* state)
{
	// current is set to the current state of the player and the 
	// Observers are notified that an update of state has happened
	current = state;
	notifyObserver();
}

PlayerState * Player::getCurrentState()
{
	return current; // returns the current state to another class
}
PlayerState * Player::getBattleState()
{
	return battleState; // returns the battle state to another class
}
PlayerState * Player::getExplorationState()
{
	return explorationState; // returns the exploration state to another class
}
PlayerState * Player::getIdleState()
{
	return idleState; // returns the hub state to another class
}
PlayerState * Player::getLootState()
{
	return lootState; // returns the loot state to another class
}
PlayerState * Player::getNPCConverseState()
{
	return npcConverseState; // returns the NPCConverse state to another class
}
PlayerState * Player::getTravellingState()
{
	return travellingState; // returns the PlanetGeneration state to another class
}
PlayerState * Player::getGameEndState()
{
	return gameEndState; // returns the GameEnd state to another class
}


void Player::setHealth(float newHealth) // Trigggered when the player uses a healthkit
{
	health = newHealth;	
}

void Player::setEnergy(int newEnergy) // The player loses energy when travelling around a planet
{
	energy = newEnergy;
}

void Player::setDamage(int newDamage) // Sets the players damage based on the equipment they are currenly using. This is affected by the equiped weapon.
{
	damage = newDamage;
}

void Player::setMoney(int newMoney) // Sets the players money after a shop transaction
{
	money = newMoney;
}

void Player::setResources(int newAmount) // The player can be rewarded with a resource at the end of a battle
{
	resources = newAmount;
}

void Player::setHealthKits(int newAmount) // The player can be rewarded with a health kit at the end of a battle 
{
	healthKits = newAmount;
}

void Player::setGoods(int newAmount) // The player can be rewarded with goods at the end of a battle 
{
	goods = newAmount;
}
void Player::setDefaultInventory() // Will initialise all inventory slots to be a blank space so that they are not null
{
	for (int i = 0; i < 10; i++)
	{
		inventoryList[i] = "";

	}
}
void Player::setInventory(string invString) 
// Will find the first blank space in the players inventory place a new item there.
// This would be triggered by picking up and item. It would also stop the array being overloaded.
{
	bool setSlot = true;
	for (int i = 0; i < 10; i++)
	{
		if (inventoryList[i] == "" && setSlot)
		{
			invString += inventoryList[i];
			setSlot = false;
		}

	}
}


string Player::getInventory() // Outputs each item in the inventory on a seperate line when the player checks their inventory.
{
	string output = "";
	for (int i = 0; i < 10; i++)
	{
		output += inventoryList[i] + "\n";

	}
	return output;
}


void Player::registerObserver(Observer * observer) // Registers a new observer
{
	observers.push_back(observer); // Adds new element at the end of the vector.
}

// This method implements the removal of the observer from the Observers vector
void Player::removeObserver(Observer* observer)
{
	vector<Observer*>::iterator it = find(observers.begin(), observers.end(), observer);
	if (it != observers.end())
	{
		swap(*it, observers.back()); // swaps the Observer to the end of the vector so it can be popped off of the back
		observers.pop_back(); // Removes the last element in the vector
	}
}

// This method notifies the Observer when the event of interest (in this case a change in state) has happened
void Player::notifyObserver()
{
	for (vector<Observer*>::iterator it = observers.begin(); it < observers.end(); it++)
	{
		(*it)->update(this);
		// traverses through the vector and updates each Observer
	}
}