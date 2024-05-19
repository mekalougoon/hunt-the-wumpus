/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Hazard Class Definition File
**************************************************/

#include "Hazard.h"

// constructors
Hazard::Hazard() {
	hazardLocation = 0;
	hazardArt = "";
	hazardSpecial = 0;
}
Hazard::Hazard(string art) {
	// +1 so hazard can't be assigned to starting location
	hazardLocation = rand() % 19 + 1;
	hazardArt = art;
	hazardSpecial = 0;
}
Hazard::~Hazard() {
}

// accessor methods
int Hazard::getHazardLocation() {
	return hazardLocation;
}

string Hazard::getHazardDetails() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardDetails;
	// testing line hazardDetails << "\n hazard location test: in location " << hazardLocation;
	hazardDetails << "\n" << hazardArt;
	hazardDetails << "\n\n This is where the description of a hazard would go... If you're seeing this, something went wrong!";
	return hazardDetails.str();
}
string Hazard::getHazardHint() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardHint;
	hazardHint << "\n This is where the hint for a hazard will go... If you're seeing this, something went wrong!";
	return hazardHint.str();
}
string Hazard::testHazardLocation() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardLocations;
	hazardLocations << "\n hazard location test: in location " << hazardLocation;
	return hazardLocations.str();
}
int Hazard::special() {
	int special = 0;
	return special;
}
string Hazard::getHazardArt() {
	return hazardArt;
}

// mutator methods
void Hazard::setHazardLocation(int location) {
	hazardLocation = location;
}
void Hazard::setHazardArt(string art) {
	hazardArt = art;
}