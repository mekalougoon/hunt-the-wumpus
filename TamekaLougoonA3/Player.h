/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Player Class Header File
**************************************************/

#ifndef Player_H
#define Player_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Player {
public:
	// constructor
	Player();
	Player(string name, int turns, int attacks);
	~Player();

	// accessor methods
	string getPlayerName();
	string getPlayerDetails();
	int getPlayerLocation();
	int getNumTurns();
	int getNumAttacks();
	int getMaxTurns();
	int getMaxAttacks();

	// mutator methods
	void setPlayerName(string name);
	void setPlayerLocation(int location);
	void setNumTurns();
	void setNumAttacks();
	void setMaxTurns(int turns);
	void setMaxAttacks(int attacks);

private:
	string playerName;
	int playerLocation;
	int numTurns;
	int maxTurns;
	int numAttacks;
	int maxAttacks;

};
#endif