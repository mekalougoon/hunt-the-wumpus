/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Witch Crypt Definition File
**************************************************/

#include "Crypt.h"

Crypt::Crypt() {
}

Crypt::Crypt(string art) : Hazard(art) {
}

// accessors
string Crypt::getHazardDetails() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardDetails;
	// testing line hazardDetails << "\n hazard location test: in location " << hazardLocation;
	hazardDetails << "\n" << hazardArt;
	hazardDetails << "\n\n Looking around the new land the portal has dropped you in, an uneasy feeling settles in your stomach. ";
	hazardDetails << "\n There's something in the air that makes the place feel... dead.";
	hazardDetails << "\n\n Then, you see the ominous building in the distance. Even from here, you can tell exactly what it is: a crypt.";
	hazardDetails << "\n Dread settles in your stomach as you remember all of the stories of corrupted crypts from your childhood.";
	hazardDetails << "\n\n Wobbling unsteadily where you stand, you pull the staff in front of you, but even its power can't protect you. ";
	hazardDetails << "\n The dead swarm towards you and well... you never stood a chance. You can't kill something if it's already dead, after all.\n\n";
	return hazardDetails.str();
}string Crypt::testHazardLocation() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardLocations;
	hazardLocations << "\n crypt location test: in location " << hazardLocation;
	return hazardLocations.str();
}
string Crypt::getHazardHint() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardHint;
	hazardHint << "\n It's quiet. Too quiet...";
	// add other details here
	return hazardHint.str();
}
