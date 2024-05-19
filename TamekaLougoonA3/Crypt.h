/**************************************************
 Project: Assignment 3
 Author: Tameka Lougoon
 Purpose: Quicksand Class Header File
**************************************************/

#ifndef Crypt_H
#define Crypt_H

#include "Hazard.h"

using namespace std;

class Crypt : public Hazard {
public:
	Crypt();
	Crypt(string art);

	// accessor methods
	virtual string getHazardDetails();
	virtual string getHazardHint();
	virtual string testHazardLocation();

private:
};

#endif 