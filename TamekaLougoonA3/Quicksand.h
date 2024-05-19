/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Quicksand Class Header File
**************************************************/

#ifndef Quicksand_H
#define Quicksand_H

#include "Hazard.h"

using namespace std;

class Quicksand : public Hazard {
public:
	Quicksand();
	Quicksand(string art);

	// accessor methods
	virtual string getHazardDetails();
	virtual string getHazardHint();
	virtual int special();
	virtual string testHazardLocation();

private:
};

#endif 