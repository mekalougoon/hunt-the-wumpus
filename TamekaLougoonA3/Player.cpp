/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Player Class Definition File
**************************************************/

#include "Player.h"


// constructors
Player::Player() {
	playerName = "";
	playerLocation = 0;
	maxTurns = 0;
	maxAttacks = 0;
	numTurns = 0;
	numAttacks = 0;
}
Player::Player(string name, int turns, int attacks) {
	playerName = name;
	playerLocation = 0;
	maxTurns = turns;
	maxAttacks = attacks;
	numTurns = maxTurns;
	numAttacks = maxAttacks;
}
Player::~Player() {
}

// accessors
string Player::getPlayerName() {
	return playerName;
}
string Player::getPlayerDetails() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream playerDetails;
	playerDetails << " Strength of life force (turns remaining): " << numTurns;
	playerDetails << "\n Number of attacks remaining: " << numAttacks;
	// add other details here
	return playerDetails.str();
}
int Player::getPlayerLocation() {
	return playerLocation;
}
int Player::getNumTurns() {
	return numTurns;
}
int Player::getNumAttacks() {
	return numAttacks;
}
int Player::getMaxTurns() {
	return maxTurns;
}
int Player::getMaxAttacks() {
	return maxAttacks;
}

// mutators
void Player::setPlayerName(string name) {
	// code from week 7 lab
	if (name.length() > 0) {
		playerName = name;
	}
	else {
		cout << "Error! Please enter at least one character.";
		system("PAUSE");
	}
}
void Player::setPlayerLocation(int location) {
	playerLocation = location;
}
void Player::setNumTurns() {
	numTurns = numTurns--;
}
void Player::setNumAttacks() {
	numAttacks = numAttacks--;
}
void Player::setMaxTurns(int turns) {
	maxTurns = turns;
	numTurns = maxTurns;
}
void Player::setMaxAttacks(int attacks) {
	maxAttacks = attacks;
	numAttacks = maxAttacks;
}



