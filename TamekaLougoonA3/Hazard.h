/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Hazards Class Header File
**************************************************/

#ifndef Hazard_H
#define Hazard_H


#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Hazard {
public:
	// constructor
	Hazard();
	Hazard(string art);
	~Hazard();

	// accessor methods
	int getHazardLocation();
	string getHazardArt();
	virtual string getHazardDetails();
	virtual string getHazardHint();
	virtual int special();
	virtual string testHazardLocation();

	// mutator methods
	void setHazardLocation(int location);
	void setHazardArt(string art);

protected:
	string hazardName;
	int hazardLocation;
	int hazardSpecial;
	string hazardArt;
};
#endif