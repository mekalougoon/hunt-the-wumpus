/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Location Class Definition File
**************************************************/

#include "Location.h"

// constructors
Location::Location() {
	locName = "";
	locDescription = "";
	locExits = "";
	locArt = "";
}
Location::Location(string name, string description, string exits, string art) {
	locName = name;
	locDescription = description;
	locExits = exits;
	locArt = art;
}
Location::~Location() {
}

// accessors
string Location::getLocName() {
	return locName;
}
string Location::getLocDescription() {
	return locDescription;
}
string Location::getLocExits() {
	return locExits;
}
string Location::getLocArt() {
	return locArt;
}
string Location::getLocDetails() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream locDetails;
	locDetails << "\n" << locArt;
	locDetails << "\n\n" << locName;
	locDetails << "\n\n" << locDescription;
	locDetails << "\n Visble Portals: [" << locExits << "]\n";
	// add other details here
	return locDetails.str();
}

// mutators
void Location::setLocName(string name) {
	locName = name;
}
void Location::setLocDescription(string description) {
	locDescription = description;
}
void Location::setLocExits(string exits) {
	locExits = exits;
}
void Location::setLocArt(string art) {
	locArt = art;
}


