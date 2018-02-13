/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "IdleState.h"

IdleState::IdleState()
{
	//empty constructor
}

void IdleState::handle(Player * player)
{
	// Handler to process the updates from the user and move onto the correct state. 
	//This is now done by the Menu which accesses state's ID.
}

stateName IdleState::getID()
{	
	return  stateName::IDLE;
	// Returns the enum for the state which matches up with the switch case in the Menu class to output to appropriate text 
	// Based on which state the player is in.
}
