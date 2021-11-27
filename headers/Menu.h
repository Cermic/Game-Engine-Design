/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once
#include "Player.h"
#include "Observer.h"
#include "Utilities/random.h"
#include "NPCs/NPCGenerator.h"
#include "Planet/PlanetGenerator.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::basic_ios;
using std::basic_istream;
using std::numeric_limits;
using std::streamsize;
// includes all of these to maintain input , output 
// and functions that catch user errors during input requests

class Menu : public Observer
{

private:
	NPCGenerator npcGenerator;
	AbstractSupplier* supplies;
	AbstractSupplier* weapons;
	AbstractHealer* heals;
	AbstractEnemyNPC* mob;
	AbstractPlanet* planet;
	PlanetGenerator pG;
	// Declaration of objects needed to interact with the player.
	int upgradeAmount=0;
	int conversationStage;
	// Menu variables declared
public:
	Menu();
	virtual ~Menu()//virtual destructor
	{
		delete this;
	}
	void idleText(Player * player);
	void travellingText(Player * player);
	void lootingText(Player * player);
	void battleText(Player * player);
	void npcConverse(Player* player);
	void exploreText(Player * player);
	// Methods for generating a text interface for the player.
	void update(Subject* player);
	// Method to update menu's text output based on the player's state.
};

