/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Player.h"
#include "Menu.h"

int main()
{
	Menu menu; // Creates a menu object
	Player player; // Creates a menu object
	player.registerObserver(&menu); //Registers an observer, in this case the menu object and takes address of the variable
	menu.update(&player); // Updates the Observer (menu) to check the Subject's (player) state at the start of that game.
}