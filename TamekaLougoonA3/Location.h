/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Location Class Header File
**************************************************/

#ifndef Location_H
#define Location_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Location {
public:
	// constructor
	Location();
	Location(string name, string description, string exits, string art);
	~Location();

	// accessor methods
	string getLocName();
	string getLocDescription();
	string getLocExits();
	string getLocDetails();
	string getLocArt();


	// mutator methods
	void setLocName(string name);
	void setLocDescription(string description);
	void setLocExits(string exits);
	void setLocArt(string art);

private:
	string locName;
	string locDescription;
	string locExits;
	string locArt;
};
#endif 

