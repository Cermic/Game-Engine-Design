#pragma once

#include "Observer.h"
#include "Subject.h"
#include "Player.h"

class Target :public Player, public Observer
{
public:
	Target(Player *player);

	void update(Subject* subject);
};