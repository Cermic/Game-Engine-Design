/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Menu.h"

Menu::Menu()
{
}
//energy, resources and helath kits

void Menu::update(Subject* p)
{
	Player * player = dynamic_cast<Player *>(p);
	// this takes p , an object of type Subject and casts(converts) it to a player object and then assigns the pointer * player.

	if (player != nullptr) // checks to see if the pointer to the player is not null.
	{
		switch (player->getCurrentState()->getID())
			// A series of switch cases to check which is the current state. It does this by looking for the ID 
			// of the current state. All states contain their own unique ID. 
			// it then compares the ID with the switch case to determine the state

			// Once a state has been determined the menu outputs the appropriate text interface
			// For the player
		{
		case stateName::IDLE:
		{
			idleText(player);
			break;
		}
		case stateName::BATTLE:
		{
			battleText(player);
			break;
		}
		case stateName::NPCCON:
		{
			npcConverse(player);
			break;
		}
		case stateName::EXPLORE:
		{
			exploreText(player);
			break;
		}
		case stateName::TRAVEL:
		{
			travellingText(player);
			break;
		}
		case stateName::LOOT:
		{
			lootingText(player);
			break;
		}

		default:
			break;
		}
	}
}

void Menu::exploreText(Player* player) 
{
	// Allows the player to explore the planet
	int input =100;
	do {
		int battleChance = (int)rnd(1, 4); // defines a random number for a chance of having a battle.

		if(battleChance == 4 || battleChance==3)
		{
			// If the correct random number is generated then the player starts a battle and is transferred to battle state.
			cout << "You are charged upon by a random enemy" << endl;
			player->setCurrentState(player->getBattleState());
		}

		cout << "Choose the direction you wish to travel in." << endl;
		do {
			// The player is asked which direction they want to travel in.
			// Each time they travel they lose energy.
			cout << "0: Exit Game" << endl;
			cout << "1: Head North" << endl;
			cout << "2: Head East" << endl;
			cout << "3: Head south" << endl;
			cout << "4: Head west" << endl;
			cout << "5: Use ration" << endl;
			cout << "6: Return to wormhole" << endl;
			cout << "7: View player details" << endl;
			cin >> input;
			switch (input)
			{
			case 0:
				cout << "Bye" << endl;
				player->setCurrentState(player->getGameEndState());
				player->getCurrentState()->handle(player);
				// Players exits the game and is set to the game end state.
				break;
			case 1:
				cout << "You move North" << endl;
				player->setEnergy((player->getEnergy())-1);
				break;
			case 2:
				cout << "You move East" << endl;
				player->setEnergy((player->getEnergy()) - 1);
				break;
			case 3:
				cout << "You move South" << endl;
				player->setEnergy((player->getEnergy()) - 1);
				break;
			case 4:
				cout << "You move West" << endl;
				player->setEnergy((player->getEnergy()) - 1);
				break;
			// the player loses 1 energy for every time they move.
			case 5:
				if (player->getResources() > 0)
				{
					cout << "You use a ration to increase your energy" << endl;
					player->setResources((player->getResources()) - 1);
					player->setEnergy(10);
				}
				else 
				{
					cout << "You have no rations left? Maybe you should go back to the wormhole" << endl;
				}
				// The player can restore lost energy with rations. If they have none left a message is output to tell them.
				break;
			case 6:
				cout << "You decide to head back and leave via the wormhole" << endl;
				player->setCurrentState(player->getIdleState());
				// If they player decides to leave they are transferred back to the hub and into the Idle state.
				break;
			case 7:
				cout << "Health: " << player->getHealth() << endl;
				cout << "Energy: " << player->getEnergy() << endl;
				cout << "Damage: " << player->getDamage() << endl;
				cout << "Gold: " << player->getMoney() << endl;
				cout << "Inventory: "  << endl;
				cout << "Health Kits: " << player->getHealthKits() << endl;
				cout << "Rations: " << player->getResources() << endl;
				cout << "Goods: " << player->getGoods() << endl;
				break;
				// Shows the player's current stats.
			default:
				cout << "You stand looking at your surroundings, unsure of which way to go next. Now you are trying to figure out if that used up any energy. You check your stats in fear.....or do you? " << endl;
				break;
				// Catch for erroneous input.
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//	cin>>input caused a catastrophic error when a string/char was entered leading to an infinite loop of the program. 
			// This was fixed by clearing the cin and ignoring any erroneous characters.

		} while (input > 7  || player->getEnergy()>0); // The player will stay in the exploration state while they have enough energy.

		if (player->getEnergy() <= 0)
		{
			cout << "You pass out from lack of energy and wake up in sickbay in the Hub. You do not know who rescued you but you surely would have died otherwise." << endl;
			player->setCurrentState(player->getIdleState()); 
			// when the player runs out of energy they are retruned to IDLE state in the hub.
		}

	} while (player->getCurrentState() == player->getExplorationState()); // This loop will continue as long as the player remains in the exploration state.
}

void Menu::idleText(Player * player) {
	int input = 100;
	cout << "Choose your path" << endl;
	do {
			cout << "0: Exit Game" << endl;
			cout << "1: Enter Wormhole" << endl;
			cout << "2: Enter Shop" << endl;
			cout << "3: Sit down for a nice meal" << endl;
			cout << "4: View player details" << endl;
			cin.clear();
			cin >> input;
			// The player is presented with a choice on what to do.
			switch (input) 
			{
			case 0:
				cout << "Bye" << endl;
				player->setCurrentState(player->getGameEndState());
				player->getCurrentState()->handle(player); 
				// Players exits the game and is set to the game end state.
				break;
			case 1:
				if(player->getEnergy()>0) // Checks to see if the player has any energy
				{
					cout << "You head down to the wormhole. " << endl;
					player->setCurrentState(player->getTravellingState()); 
					// If they have energy remaining they are allowed to travel.
				}
				else
				{
					cout << "You feel too tired to explore today... You remember that the shops sell rations... but which one?" << endl;
					player->setCurrentState(player->getIdleState());
				}
				// Checks if the player has enough energy to travel and if they do changes the player's state to Travelling state.
				// If they do not have enough energy they are told they are too tired and given the initial options again.
				break;
			case 2:
				cout << "You walk over to one of the stalls set up near the wormhole. " << endl;
				conversationStage = 1;
				player->setCurrentState(player->getNPCConverseState());
				// If the player chooses to go to the shops they are transferred to NPC Converse state.
				break;
			case 3:
				if (player->getResources() > 0)
				{
					cout << "You get one of your rations and cook it up real nice. It tastes good even." << endl;
					player->setResources((player->getResources())-1);
					player->setEnergy(10);
					player->setCurrentState(player->getIdleState());
				}
				// When the player chooses to eat to replenish their energy they gain energy and lose a ration.
				break;
			case 4:
				cout << "Health: " << player->getHealth() << endl;
				cout << "Energy: " << player->getEnergy() << endl;
				cout << "Damage: " << player->getDamage() << endl;
				cout << "Gold: " << player->getMoney() << endl;
				cout << "Inventory: " << endl;
				cout << "Health Kits:" << player->getHealthKits() << endl;
				cout << "Rations: " << player->getResources() << endl;
				cout << "Goods: " << player->getGoods() << endl;
				player->setCurrentState(player->getIdleState());
				break;
				// Shows the player's current stats.
			default:
				cout << "You can't make up your mind and choose to get drunk. You then pass out and waste a day. The next day you decide to... " << endl;
				break;
				// Catch for erroneous input.
			} 
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//	cin>>input caused a catastrophic error when a string/char was entered leading to an infinite loop of the program. 
		// This was fixed by clearing the cin and ignoring any erroneous characters.
	} while (input > 5);
		
}

void Menu::npcConverse(Player* player) {
	int input = 100;
	do {
		if (conversationStage == 1)
		{
			input = 100;
			cout << "You look around the stalls, who do you approach?" << endl;
			do {
				cout << "0: Exit Game" << endl;
				cout << "1: Appraoch the Supplies dealer" << endl;
				cout << "2: Appraoch the Weapons dealer" << endl;
				cout << "3: Appraoch the Healer" << endl;
				cout << "4: Return to hub" << endl;
				cout << "5: View player details" << endl;
				cin >> input;
				// Presents the player with options.
				switch (input)
				{
				case 0:
					cout << "Bye" << endl;
					player->setCurrentState(player->getGameEndState());
					player->getCurrentState()->handle(player);
					// Players exits the game and is set to the game end state.
					break;
				case 1:
					cout << "You decide to go talk to the supplies dealer" << endl;
					supplies = npcGenerator.createSupplier(2);
					conversationStage = 2;
					/* When the player chooses to talk to the Supplies dealer a 
					 Supplies dealer is generated from the supplier factory */
					break;
				case 2:
					cout << "You decide to go talk to the weapons dealer" << endl;
					weapons = npcGenerator.createSupplier(1);
					conversationStage = 3;
					/* When the player chooses to talk to the Weapons dealer a
					Weapons dealer is generated from the supplier factory */
					break;
				case 3:
					cout << "You decide to go talk to the healer" << endl;
					heals = npcGenerator.createHealer(1);
					conversationStage = 4;
					/* When the player chooses to talk to the Healer a
					Healer is generated from the healer factory */
					break;
				case 4:
					cout << "You decide not to spend any money here and head back to the hub" << endl;
					player->setCurrentState(player->getIdleState());
					// The player chooses to forgoe shopping and return to the hub.
					// This sets the player back to the idle state.
					break;
				case 5:
					cout << "Health: " << player->getHealth() << endl;
					cout << "Energy: " << player->getEnergy() << endl;
					cout << "Damage: " << player->getDamage() << endl;
					cout << "Gold: " << player->getMoney() << endl;
					cout << "Inventory: " << endl;
					cout << "Health Kits: " << player->getHealthKits() << endl;
					cout << "Rations: " << player->getResources() << endl;
					cout << "Goods: " << player->getGoods() << endl;
					player->setCurrentState(player->getIdleState());
					// Displays the player's current stats.
					break;
				default:
					cout << "You stand there looking around. Your staring starts to creep out some of the merchants. " << endl;
					break;
					// Catch for erroneous input.
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//	cin>>input caused a catastrophic error when a string/char was entered leading to an infinite loop of the program. 
				// This was fixed by clearing the cin and ignoring any erroneous characters.
			} while (input > 5);
		}
		if (conversationStage == 2)
		{	// The player talks to the Supplies dealer.
			input = 100;
			cout << "Hey there sssssshonny, wanna buy shome candy?" << endl;
			do {
				cout << "0: Exit Game" << endl;
				cout << "1: Would you like to buy some rations? We are selling 3 for 10g's, great deal. Buy my Rations!" << endl;
				cout << "2: You wana buy some health kits? Alright, 10g." << endl;
				cout << "3: We convert all your junk items into shiny coins, gauranteed to be atleast 17% gold" << endl;
				cout << "4: You decide to visit one of the other shops" << endl;
				cin >> input;
				// Asks the player for input
				switch (input)
				{
				case 0:
					cout << "Bye" << endl;
					player->setCurrentState(player->getGameEndState());
					player->getCurrentState()->handle(player);
					// The player ends the game, the player's state is set to the game end state.
					break;
				case 1:
					if (player->getMoney() >= 10)// Check to see if they player has enough money to buy rations.
					{
						player->setResources(player->getResources() + 3);
						player->setMoney(player->getMoney() - 10);
						// The player buys rations and they gain 3 rations and lose 10 money.
					}
					else 
					{
						cout << "Ah it seems you dont have enough money." << endl;
						// If the player doesn't have enough money they are show the above message.
					}
					break;
				case 2:
					if (player->getMoney() >= 10) // Check to see if they player has enough money to buy health kits.
					{
						player->setHealthKits(player->getHealthKits() + 1);
						player->setMoney(player->getMoney() - 10);
						// The player buys the helath kits and they gain 1 health kit and lose 10 money.
					}
					else 
					{
						cout << "Ah it seems you dont have enough money." << endl;
						// If the player doesn't have enough money they are show the above message.
					}
					break;
				case 3:
					cout << "You will recieve "<< (player->getGoods() * 10) <<" gold"<<endl;
					player->setMoney(player->getMoney() + (player->getGoods() * 10));
					player->setGoods(0);
					// Shows the player how much money they will recieve and set's their goods back to 0.
					break;
				case 4:
					// The player leaves the Supplier shop and returns to the menu asking them which shop they would like to visit
					conversationStage = 1;
					break;
				default:
					cout << "You eye the shopkeeper warily. Repressed childhood memories bubble near the surface. " << endl;
					break;
					// Catch for erroneous input.
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//	cin>>input caused a catastrophic error when a string/char was entered leading to an infinite loop of the program. 
				// This was fixed by clearing the cin and ignoring any erroneous characters.
			} while (input > 4); // Until the player gives a valid input the menu will loop.
		}
		if (conversationStage == 3)
		{
			// The player talks to the Weapons dealer.
			input = 100;
			cout << "That weapon is starting to look a little rusty..." << endl;
			do {
				cout << "0: Exit Game" << endl;
				cout << "1: Hand me your weapon and i'll see if i can make a few upgrades......for a price of course (10g)" << endl;
				cout << "2: You decide to visit one of the other shops" << endl;
				cin >> input;
				// Asks the player for input
				switch (input)
				{
				case 0:
					cout << "Bye" << endl;
					player->setCurrentState(player->getGameEndState());
					player->getCurrentState()->handle(player);
					// The player ends the game, the player's state is set to the game end state.
					break;
				case 1:
					if (player->getMoney() >= 10)// Check to see if they player has enough money to buy a weapon upgrade. 
					{
						upgradeAmount = (int)rnd(1, 3);
						player->setDamage(player->getDamage() + upgradeAmount);
						player->setMoney(player->getMoney() - 10);
						// The player's weapon is upgraded and they lose 10 money.
					}
					else 
					{
						cout << "Ah it seems you dont have enough money." << endl;
						// If the player doesn't have enough money they are show the above message.
					}
					break;
				case 2:
					// The player leaves the Weapon shop and returns to the menu asking them which shop they would like to visit
					conversationStage = 1;
					break;
				default:
					cout << "Slightly insulted, you inspect your weapon and see that it is a little dented. " << endl;
					break;
					// Catch for erroneous input.
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//	cin>>input caused a catastrophic error when a string/char was entered leading to an infinite loop of the program. 
				// This was fixed by clearing the cin and ignoring any erroneous characters.
			} while (input > 2); // Until the player gives a valid input the menu will loop.
		}
		if (conversationStage == 4)
		{
			// The player talks to the Healer.
			input = 100;
			cout << "Hey, that cut is starting to look a little infected, should probably get that looked at......" << endl;
			do {
				cout << "0: Exit Game" << endl;
				cout << "1: Heal me" << endl;
				cout << "2: You decide to visit one of the other shops" << endl;
				cin >> input;
				// Asks for player input.
				switch (input)
				{
				case 0:
					cout << "Bye" << endl;
					player->setCurrentState(player->getGameEndState());
					player->getCurrentState()->handle(player);
					// The player ends the game, the player's state is set to the game end state.
					break;
				case 1:
					if (player->getMoney() >= 10) // Check to see if they player has enough money to get healed.
					{
						cout << "Just give me a sec, this shouldn't hurt much...." << endl;
						player->setHealth(100);
						player->setMoney(player->getMoney() - 10);
						// The player is healed back to full health and they lose ten money.
					}
					else 
					{
						cout << "Ah it seems you dont have enough money." << endl;
						// If the player doesn't have enough money they are show the above message.
					}
					break;
				case 2:
					// The player leaves the Healer shop and returns to the menu asking them which shop they would like to visit
					conversationStage = 1;
					break;
				default:
					cout << "You tell the healer that its fine, it'll go away by itself, you dont really need to see a doctor. But you dont leave. " << endl;
					break;
					// Catch for erroneous input.
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//	cin>>input caused a catastrophic error when a string/char was entered leading to an infinite loop of the program. 
				// This was fixed by clearing the cin and ignoring any erroneous characters.
			} while (input > 2); // Until the player gives a valid input the menu will loop.
		}
	}while (player->getCurrentState() == player->getNPCConverseState()); // The main loop will continue until the player leaves NPC Converse state.
}

void Menu::travellingText(Player * player) 
{
	// The player decides to travel to a planet.
	int input = 100;
	cout << "Do you wish to visit the planet?"<< endl;
	do {
		planet = pG.generatePlanet(); // A planet is generated from the factory.
		cout << "Planet type is";
		planet->render(); // The player is shows the planet type.
		cout << "0: Exit Game" << endl;
		cout << "1: Visit planet"<< endl;
		cout << "2: Search for a new planet" << endl;
		cout << "3: Return to hub" << endl;
		cout << "4: View player details" << endl;
		cin >> input;
		// The player is presented with a choice on what to do.
		switch (input) 
		{
		case 0:
			cout << "Bye" << endl;
			player->setCurrentState(player->getGameEndState());
			player->getCurrentState()->handle(player);
			// Players exits the game and is set to the game end state.
			break;
		case 1:
			cout << "You decide to visit this planet and enter the wormhole" << endl;
			player->setCurrentState(player->getExplorationState());
			// If the player decided to visit the planet they are transfered to the exploration state.
			break;
		case 2:
			cout << "This planet doesnt seem to have anything of value nearby, you check for another available planet" << endl;
			player->setCurrentState(player->getTravellingState());
			// If the player decided they would like a different planet they choose this option and another one is generated.
			// Maintains the player in the travelling state.
			break;
		case 3:
			cout << "There does not appear to be any decent planets available at the moment, you head back to the center of the hub." << endl;
			player->setCurrentState(player->getIdleState());
			// The player returns back to the hub and is tranferred to the idle state.
			break;
		case 4:
			cout << "Health: " << player->getHealth() << endl;
			cout << "Energy: " << player->getEnergy() << endl;
			cout << "Damage: " << player->getDamage() << endl;
			cout << "Gold: " << player->getMoney() << endl;
			cout << "Inventory: " << endl;
			cout << "Health Kits: " << player->getHealthKits() << endl;
			cout << "Rations: " << player->getResources() << endl;
			cout << "Goods: " << player->getGoods() << endl;
			player->setCurrentState(player->getIdleState());
			// Shows the player's current stats.
			break;
		default:
			cout << "You stare at the panel on the side of the gate. Someone in the queue behind you shouts something inaudible and probably rude." << endl;
			break;
			// Catch for erroneous input.
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//	cin>>input caused a catastrophic error when a string/char was entered leading to an infinite loop of the program. 
		// This was fixed by clearing the cin and ignoring any erroneous characters.
	} while (input > 4);
}

void Menu::lootingText(Player * player) {
	int lootNum = (int)rnd(1, 3); 
	int lootQuant = (int)rnd(1, 3);
	// Generates a random number to decide how much loot to give the player
	// If they win a battle.

	if (lootNum == 1) 
	{
		player->setHealthKits(player->getHealthKits() + lootQuant); // Adds the amount of the reward to the player's stats.
		if(lootQuant>1)
		{ 
		cout << "You recieved: " << lootQuant << " health kits" <<endl;
		//  Tells the player how many health kits they recieved.
		}
		else
		{
			cout << "You recieved: " << lootQuant << " health kit" << endl;
			// If they recieve only one the spelling is changed to reflect this.
		}
	}
	else if (lootNum == 2) 
	{
		player->setGoods(player->getGoods() + lootQuant); // Adds the amount of the reward to the player's stats.
		if (lootQuant>1)
		{
			cout << "You recieved: " << lootQuant << " goods" << endl;
			//  Tells the player how many goods they recieved.
		}
		else
		{
			cout << "You recieved: " << lootQuant << " good" << endl;
			// If they recieve only one the spelling is changed to reflect this.
		}
	}
	else if (lootNum==3)
	{
		player->setResources((player->getResources())+lootQuant); // Adds the amount of the reward to the player's stats.
		if (lootQuant>1)
		{
			cout << "You recieved: " << lootQuant << " rations" << endl;
			//  Tells the player how many rations they recieved.
		}
		else
		{
			cout << "You recieved: " << lootQuant << " ration" << endl;
			// If they recieve only one the spelling is changed to reflect this.
		}
	}
	
	player->setCurrentState(player->getExplorationState());
	player->getCurrentState()->handle(player);
	// After the player recieves their loot they are transfered back to the exploration state.
}

void Menu::battleText(Player * player) {
	int input = 100;
	mob = npcGenerator.createEnemy();
	mob->displayNPC();
	// An enemy NPC is created from the factory and displyaed to the player.
	cout << "Health: " << mob->getHP() << endl;
	cout << "Damage: " << mob->getDamage() << endl;
	// Shows the player the health and damage of the enemy they are fighting.
	cout << "Choose your action" << endl;
	// Asks the player to choose an option.
	do {
		cout << "0: Exit Game" << endl;
		cout << "1: Attack" << endl;
		cout << "2: Use health kit" << endl;
		cout << "3: Retreat to wormhole" << endl;
		cout << "4: View player details" << endl;
		cin >> input;
		// The player is presented with a choice on what to do.
		switch (input) 
		{
		case 0:
			cout << "Bye" << endl;
			player->setCurrentState(player->getGameEndState());
			player->getCurrentState()->handle(player);
			// Players exits the game and is set to the game end state.
			break;
		case 1:
			cout << "You relentlessly attack your foe" << endl; 
			// Tells the player they are attacking.
			mob->setHP(mob->getHP() - player->getDamage()); 
			// Takes the player's damage and applies it to the enemy. The enemy loses the coresponding amount of health.
			cout << "Enemy health: " << mob->getHP() << endl; 
			// Shows the new enemy health.
			if (mob->getHP() > 0) // Check to see if the enemy is still alive and able to fight.
			{
				cout << "The enemy attacks you back" << endl;  
				// Tells the player the enemy attack them.
				player->setHealth(player->getHealth() - mob->getDamage()); 
				// Takes the enemy's damage and applies it to the player. The player loses the coresponding amount of health.
				cout << "Your health: " << player->getHealth() << endl;
				// Shows the new player health.
			}
			break;
		case 2:
			cout << "You look into your bag during a lul in the battle" << endl;
			if (player->getHealthKits() > 0) // Checks to see if the player has any health kits left.
			{
				player->setHealthKits((player->getHealthKits())-1); 
				// Removes one health kit from the player's inventory.
				player->setHealth(player->getHealth() + 50);
				// Gives the player 50 health.
				if (player->getHealth() > 100)// Checks to see if the player's health has exceed 100 
				{
					player->setHealth(100); // Sets the player's health to 100. This stops the player having more than 100 health.
				}
				cout << "You used 1 health kit" << endl;
				// Tells the player they have used a health kit.
			}
			else
			{
				cout << "Your face goes pale as you realise there is only crumbs from that biscuit you ate earlier in you bag now... All the health kits are gone." << endl;
				// If the player has no health kits they are shown the above message.
			}
			break;
		case 3:
			cout << "Realising you cannot defeat this foe, you retreat to the wormhole" << endl;
			player->setCurrentState(player->getIdleState());
			// The player chooses to flee the battle and return to the hub.
			// The player is set to the idle state.
			break;
		case 4:
			cout << "Health: " << player->getHealth() << endl;
			cout << "Energy: " << player->getEnergy() << endl;
			cout << "Damage: " << player->getDamage() << endl;
			cout << "Gold: " << player->getMoney() << endl;
			cout << "Inventory: " << endl;
			cout << "Health Kits: " << player->getHealthKits() << endl;
			cout << "Rations: " << player->getResources() << endl;
			cout << "Goods: " << player->getGoods() << endl;
			break;
			// Shows the player's current stats.
		default:
			cout << "You stare at the enemy, unsure what to do next. Are you frozen with fear?" << endl;
			cout << "The enemy sees this advantage and attacks you " << endl;
			// If they player puts in an invalid option the enemy attacks them.
			player->setHealth(player->getHealth() - mob->getDamage());
			// Takes the enemy's damage and applies it to the player. The player loses the coresponding amount of health.
			cout << "Your health: " << player->getHealth() << endl;
			// Shows the player's new health.
			break;
		}
	} while (player->getHealth() > 0 && mob->getHP() > 0); // Continues the battle until either the player or enemy die.

	if (player->getHealth() <= 0) 
	{
		player->setCurrentState(player->getGameEndState());
		// If the player dies the game ends.
		// They are transferred to the game end state.
	}
	else
	{
		delete mob;
		player->setCurrentState(player->getLootState());
		// If the player wins the match the enemy object is deleted and the player
		// is transferred to the loot state and given their reward.
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//	cin>>input caused a catastrophic error when a string/char was entered leading to an infinite loop of the program. 
	// This was fixed by clearing the cin and ignoring any erroneous characters.
}