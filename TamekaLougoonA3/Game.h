/**************************************************
 Project: Assignment 2
 Author: Tameka Lougoon
 Purpose: Header File
 Hunting The Witch of Caverton Realms Game
**************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

#include "Player.h"
#include "Location.h"
#include "Hazard.h"

#include "Witch.h"
#include "Quicksand.h"
#include "Crypt.h"

using namespace std;

// function prototypes
void startGame();
void playTheGame(int difficulty);

// set up the game
void setUpGame(int difficulty);
void addPlayer(int difficulty);
void displayBlurb();
void displayTitle();
void addHazards();
void addLocations(string myFile);

// playing the game functions
void movePlayer();
void displayMap();
void displayHelp();
void hazardAction();
void playerAttack();
void getHint();
string checkGameStatus();
string askForString(string question);

// end the game
void displayStats(int score, string gameStatus);
void deleteHazards();

// extra functionality
int setMoveWitch();
void moveWitch(int difficulty);
int setDifficulty();
int determineScore(int difficulty, string gameStatus);

vector<Location*>gameLocs;
vector<Player>gamePlayers;
vector<Hazard*>gameHazards;

string playerChoice = "";
string deathCause = "";
int attackOutcome = 0; // 0 miss, 1 hit
int moveNumber = 0;