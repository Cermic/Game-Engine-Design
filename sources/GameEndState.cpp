/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "GameEndState.h"

GameEndState::GameEndState()
{
	//empty constructor
}

void GameEndState::handle(Player * player)
{
	gameEnd(); // when the handle is called the game ends.
}

stateName GameEndState::getID()
{
	return  stateName::GAMEEND;
	// Returns the enum for the state which matches up with the switch case in the Menu class to tell the program to close.
}
