/*

Name: Jack D Smith, Rhys Murray, Greg Smith

Student ID: B00308927, B00308897, B00308929

I declare that the following code was produced by (Jack D Smith, Rhys Murray & Greg Smith) as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once
#include "Observer.h"
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::swap;

class Subject
{
protected:
	vector<Observer*> observers; // Creates a vector of Observers for the Subject to update
public:
	virtual void registerObserver(Observer* observer) = 0;// Virtual method for the Subjects to implement
	virtual void notifyObserver() = 0; // Virtual method for the Subjects to implement
	virtual void removeObserver(Observer* observer) = 0; // Virtual method for the Subjects to implement

};
