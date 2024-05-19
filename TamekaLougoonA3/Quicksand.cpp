/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Quicksand Class Definition File
**************************************************/

#include "Quicksand.h"

Quicksand::Quicksand() {
}

Quicksand::Quicksand(string art) : Hazard(art) {
}

// accessors

string Quicksand::getHazardDetails() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardDetails;
	// testing line hazardDetails << "\n hazard location test: in location " << hazardLocation;
	hazardDetails << "\n" << hazardArt;
	hazardDetails << "\n\n You take a few steps away from the portal and notice that the ground feels... odd... under your feet.";
	hazardDetails << "\n After a few more moments, your feet have disappeared entirely!";
	hazardDetails << "\n\n Oh no! It seems you managed to walk straight into a pit of quicksand.";
	hazardDetails << "\n I don't know how you didn't see it... it really was quite obvious.";
	hazardDetails << "\n\n You feel yourself slowly sinking, lower, l o w e r, until... wait, where are you? It seems like you feel so deeply into the quicksand that you've fallen right through to another land!"; 
	hazardDetails << "\n Time to find your bearings and continue back on your way...\n\n";
	return hazardDetails.str();
}
string Quicksand::getHazardHint() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardHint;
	hazardHint << "\n The ground looks awfully suspicious over there...";
	return hazardHint.str();
}

string Quicksand::testHazardLocation() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardLocations;
	hazardLocations << "\n quicksand location test: in location " << hazardLocation;
	return hazardLocations.str();
}
int Quicksand::special() {
	int newLocation = rand() % 19 + 1;
	return newLocation;
}
