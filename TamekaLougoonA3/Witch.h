/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Witch Class Header File
**************************************************/

#ifndef Witch_H
#define Witch_H

#include "Hazard.h"

using namespace std;

class Witch : public Hazard {
public:
	Witch();
	Witch(string art);

	// accessor methods
	virtual string getHazardDetails();
	virtual string getHazardHint();
	virtual string testHazardLocation();
	virtual int special();

private:
};

#endif 