/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Witch Class Definition File
**************************************************/

#include "Witch.h"

Witch::Witch() {

}

Witch::Witch(string art) : Hazard(art) {

}

// accessors
string Witch::getHazardDetails() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardDetails;
	// testing line hazardDetails << "\n hazard location test: in location " << hazardLocation;
	hazardDetails << "\n" << hazardArt;
	hazardDetails << "\n\n You've been confronted by the witch.";
	hazardDetails << "\n Her lips curl up into a wicked grin and you know that you stand no chance.";
	hazardDetails << "\n\n You know that you've met your fate: she'll finish off what she started...\n\n";
	return hazardDetails.str();
}
string Witch::getHazardHint() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardHint;
	hazardHint << "\n Your soul hums in the presence of its missing piece...";
	return hazardHint.str();
}
string Witch::testHazardLocation() {
	// code adapted from week 7 lab
	// returns a formatted string
	stringstream hazardLocations;
	hazardLocations << "\n witch location test: in location " << hazardLocation;
	return hazardLocations.str();
}
int Witch::special() {
	int newLocation = 0;
	int randomValue = rand() % 3 + 1;
	// select adjoining cave to move witch to
	switch (hazardLocation) {
	case 1:
		switch (randomValue) {
		// witch can't move to "spawn" of the game"
		case 1:
		case 2:
			newLocation = 3;
			break;
		case 3:
			newLocation = 6;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 2:
		switch (randomValue) {
			// witch can't move to "spawn" of the game"
		case 1:
		case 2:
			newLocation = 7;
			break;
		case 3:
			newLocation = 4;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 3:
		switch (randomValue) {
		case 1:
			newLocation = 1;
			break;
		case 2:
			newLocation = 6;
			break;
		case 3:
			newLocation = 8;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 4:
		switch (randomValue) {
		case 1:
			newLocation = 2;
			break;
		case 2:
			newLocation = 7;
			break;
		case 3:
			newLocation = 9;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 5:
		switch (randomValue) {
			// witch can't move to "spawn" of the game"
		case 1:
		case 2:
			newLocation = 11;
			break;
		case 3:
			newLocation = 12;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 6:
		switch (randomValue) {
		case 1:
			newLocation = 1;
			break;
		case 2:
			newLocation = 3;
			break;
		case 3:
			newLocation = 10;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 7:
		switch (randomValue) {
		case 1:
			newLocation = 2;
			break;
		case 2:
			newLocation = 4;
			break;
		case 3:
			newLocation = 10;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 8:
		switch (randomValue) {
		case 1:
			newLocation = 3;
			break;
		case 2:
			newLocation = 11;
			break;
		case 3:
			newLocation = 13;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 9:
		switch (randomValue) {
		case 1:
			newLocation = 4;
			break;
		case 2:
			newLocation = 12;
			break;
		case 3:
			newLocation = 14;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 10:
		switch (randomValue) {
		case 1:
			newLocation = 6;
			break;
		case 2:
			newLocation = 7;
			break;
		case 3:
			newLocation = 15;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 11:
		switch (randomValue) {
		case 1:
			newLocation = 8;
			break;
		case 2:
			newLocation = 5;
			break;
		case 3:
			newLocation = 15;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 12:
		switch (randomValue) {
		case 1:
			newLocation = 5;
			break;
		case 2:
			newLocation = 9;
			break;
		case 3:
			newLocation = 15;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 13:
		switch (randomValue) {
		case 1:
			newLocation = 8;
			break;
		case 2:
			newLocation = 16;
			break;
		case 3:
			newLocation = 18;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 14:
		switch (randomValue) {
		case 1:
			newLocation = 9;
			break;
		case 2:
			newLocation = 17;
			break;
		case 3:
			newLocation = 19;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 15:
		switch (randomValue) {
		case 1:
			newLocation = 10;
			break;
		case 2:
			newLocation = 11;
			break;
		case 3:
			newLocation = 12;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 16:
		switch (randomValue) {
		case 1:
			newLocation = 13;
			break;
		case 2:
			newLocation = 17;
			break;
		case 3:
			newLocation = 18;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 17:
		switch (randomValue) {
		case 1:
			newLocation = 14;
			break;
		case 2:
			newLocation = 16;
			break;
		case 3:
			newLocation = 19;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 18:
		switch (randomValue) {
		case 13:
			newLocation = 2;
			break;
		case 16:
			newLocation = 7;
			break;
		case 19:
			newLocation = 9;
			break;
		default:
			newLocation = 1;
		}
		break;
	case 19:
		switch (randomValue) {
		case 1:
			newLocation = 14;
			break;
		case 2:
			newLocation = 17;
			break;
		case 3:
			newLocation = 18;
			break;
		default:
			newLocation = 1;
		}
		break;
	default:
		newLocation = 1;
}
	return newLocation;
}

