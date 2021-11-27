/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once
#include "Player.h"
#include "PlayerState.h"

class ExplorationState :public PlayerState // Inherits from player state to get the apprpriate links methods
{
public:
	ExplorationState();//class constructor
	virtual ~ExplorationState() {}//virtual destructor
	void handle(Player* player); // handler method that takes in a player - would run updates if not for the Menu being the Observer
	stateName getID(); // method to access the state's ID
};
