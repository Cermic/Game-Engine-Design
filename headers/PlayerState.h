/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once
#include "StateEnum.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Player; // Player class pre definition

class PlayerState
{
public:
	virtual ~PlayerState() {}// virtual destructor
	virtual void handle(Player* player) = 0; // Virtual handler method for the child classes to implement
	virtual stateName getID() = 0; // Virtual accessor to allow child classes to get the ID of the state
};