/**************************************************
 Project: Assignment 2
 Author: Tameka Lougoon
 Purpose: Application File
 Hunting The Witch of Caverton Realms Game
**************************************************/

#include "Game.h"

int main() {
	// seed randoms 
	srand(unsigned(time(nullptr)));
	// file functions
	startGame();
	// wait and exit
	system("PAUSE");
	return 0;
}

// file functions
void startGame() {
	displayTitle();
	displayBlurb();
	displayHelp();
	int difficulty = setDifficulty();
	setUpGame(difficulty);
	playTheGame(difficulty);
}
void playTheGame(int difficulty) {
	string gameStatus = checkGameStatus();
	int score = determineScore(difficulty, gameStatus);
	// this line of code is from week 4 lab
	string question = " what is your next move? ";
	// check input and call correct function
	while (gameStatus == "ongoing") {
		system("CLS");
		displayTitle();
		// testing line cout << numTurns;
		// display current location details
		int playerLocation = gamePlayers[0].getPlayerLocation();
		int i = playerLocation;
		cout << gameLocs[i]->getLocDetails();
		// show if there is a hazrad in locations nearby
		getHint();
		// show current player stats
		cout << "\n\n" << gamePlayers[0].getPlayerDetails();
		// cout optional choices
		cout << "\n\n For help, use [H] \n For map, use [M] \n For move, enter a visible portal \n For attack, do [shoot direction] - when attacking, please reply in all lowercase.";
		cout << "\n\n " << gamePlayers[0].getPlayerName() << ",";
		// this line of code is from week 4 lab
		playerChoice = askForString(question);
		// quit the game option
		if (playerChoice == "Q" || playerChoice == "q") {
			system("CLS");
			displayTitle();
			cout << "\n\n Thank you for playing!\n\n";
			return;
		}
		// display map option
		else if (playerChoice == "M" || playerChoice == "m") {
			displayMap();
			displayTitle();
		}
		// display help option
		else if (playerChoice == "H" || playerChoice == "h") {
			displayTitle();
			displayHelp();
		}
		// move option
		else if (playerChoice == "N" || playerChoice == "n" || playerChoice == "E" || playerChoice == "e" || playerChoice == "S" || playerChoice == "s" || playerChoice == "W" || playerChoice == "w") {
			system("CLS");
			displayTitle();
			movePlayer();
			// so that turn is only used if player actually moves, not for incorrect input
			// i will be previous location and playerLocation is current/updated location
			playerLocation = gamePlayers[0].getPlayerLocation();
			if (playerLocation != i) {
				gamePlayers[0].setNumTurns();
				// testing line cout << moveNumber;
				moveWitch(difficulty);
			}
		}
		// attack option
		else if (playerChoice == "shoot n" || playerChoice == "shoot e" || playerChoice == "shoot s" || playerChoice == "shoot w") {
			system("CLS");
			displayTitle();
			playerAttack();
			gamePlayers[0].setNumAttacks();
		}
		// incorrect output
		else {
			system("CLS");
			displayTitle();
			cout << " Incorrect Input! Please try again\n\n";
			system("PAUSE");
		}
		// check status of the game, if it is to continue
		gameStatus = checkGameStatus();
		score = determineScore(difficulty, gameStatus);
	}
	// end game, output results/final stats
	system("CLS");
	displayStats(score, gameStatus);
	// delete the hazards 
	deleteHazards();
}

// set up the game
void setUpGame(int difficulty) {
	addPlayer(difficulty);
	addLocations("");
	addHazards();
	setMoveWitch();
}
void addPlayer(int difficulty) {
	// collects and stores the users name
	system("CLS");
	displayTitle();
	string question = "\n What is your name? ";
	string playerName = "";
	playerName = askForString(question);
	Player player;
	player.setPlayerName(playerName);
	// sets stats to values corresponding to difficulty
	if (difficulty == 1) {
		player.setMaxAttacks(5);
		player.setMaxTurns(12);
	}
	else if (difficulty == 2) {
		player.setMaxAttacks(4);
		player.setMaxTurns(10);
	}
	else if (difficulty == 3) {
		player.setMaxAttacks(3);
		player.setMaxTurns(8);
	}
	gamePlayers.push_back(player);
	cout << " \n\n Well, " << playerName << ", I wish you the best of luck. It's time to move on with your journey and out into the lands.\n";
	// testing line cout << gamePlayers[0].getPlayerDetails();
	system("pause");

}
void displayBlurb() {
	// THIS CODE IS FROM WEEK 3 LAB
	// **********************************************
	//open file
	ifstream fileToRead("GameBlurb.txt");
	if (fileToRead.is_open()) {
		string myItem = "";
		// read data
		while (!fileToRead.eof()) {
			getline(fileToRead, myItem);
			cout << " " << myItem << endl;
		}
	}
	// if unnable to read file
	else {
		cout << "Unable to read the data." << endl;
	}
	system("pause");
	// close file
	fileToRead.close();
	system("CLS");
	// **********************************************
}
void displayTitle() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\t\t\t\t\t\t\t\t\tHunting The Witch of Caverton Realms\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}
void addHazards() {
	vector<string>hazardArt;
	// read in the hazard art
	// THIS CODE HAS BEEN ADAPTED FROM WEEK 4 LAB AND ASSIGNMENT ONE
	// 	   **********************************************************
	//open files
	ifstream fileToReadOne("HazardArt.txt");
	//read data
	if (fileToReadOne.is_open()) {
		string line = "";
		while (!fileToReadOne.eof()) {
			getline(fileToReadOne, line, '@');
			hazardArt.push_back(line);
		}
	}
	// if unnable to read file
	else {
		cout << "Unable to read the data." << endl;
	}
	// close file
	fileToReadOne.close();

	// add witch
	gameHazards.push_back(new Witch(hazardArt[0]));
	// line to show locations for sake of testing
	cout << gameHazards[0]->testHazardLocation();
	// add quicksand
	gameHazards.push_back(new Quicksand(hazardArt[1]));
	cout << gameHazards[1]->testHazardLocation();
	gameHazards.push_back(new Quicksand(hazardArt[1]));
	cout << gameHazards[2]->testHazardLocation();
	// add crypts
	gameHazards.push_back(new Crypt(hazardArt[2]));
	cout << gameHazards[3]->testHazardLocation();
	gameHazards.push_back(new Crypt(hazardArt[2]));
	cout << gameHazards[4]->testHazardLocation();
	cout << "\n\n";
	system("PAUSE");
}
void addLocations(string myFile) {
	vector<string>locNames;
	vector<string>locDescriptions;
	vector<string>locExits;
	vector<string>locArt;

	// read in the location details
	// THIS CODE HAS BEEN ADAPTED FROM WEEK 4 LAB AND ASSIGNMENT ONE
	// 	   **********************************************************
	//open files
	ifstream fileToReadOne("LocationNames.txt");
	ifstream fileToReadTwo("LocationDescriptions.txt");
	ifstream fileToReadThree("LocationExits.txt");
	ifstream fileToReadFour("LocationArt.txt");
	//read data
		//load location names
	if (fileToReadOne.is_open()) {
		string line = "";
		while (!fileToReadOne.eof()) {
			getline(fileToReadOne, line, '@');
			locNames.push_back(line);
		}
		/*testing code
		cout << line;
		system("pause"); */
	}
	// if unnable to read file
	else {
		cout << "Unable to read the data." << endl;
	}
	// close file
	fileToReadOne.close();

	//load location descriptions
		//read data
	if (fileToReadTwo.is_open()) {
		string line = "";
		while (!fileToReadTwo.eof()) {
			getline(fileToReadTwo, line, '@');
			locDescriptions.push_back(line);
		}
	}
	// if unnable to read file
	else {
		cout << "Unable to read the data." << endl;
	}
	// close file
	fileToReadTwo.close();

	//load location exits
			//read data
	if (fileToReadThree.is_open()) {
		string line = "";
		while (!fileToReadThree.eof()) {
			getline(fileToReadThree, line, '@');
			locExits.push_back(line);
		}
	}
	// if unnable to read file
	else {
		cout << "Unable to read the data." << endl;
	}
	// close file
	fileToReadThree.close();

	//load location ascii art
		//read data
	if (fileToReadFour.is_open()) {
		string line = "";
		while (!fileToReadFour.eof()) {
			getline(fileToReadFour, line, '@');
			locArt.push_back(line);
		}
	}
	// if unnable to read file
	else {
		cout << "Unable to read the data." << endl;
	}
	// close file
	fileToReadFour.close();
	// 	   **********************************************************

	// add the locations
	// CODE ADAPTED FROM WEEK 6 LAB
	// 	   **********************************************************
	Location locStart(locNames[0], locDescriptions[0], locExits[0], locArt[0]);
	gameLocs.push_back(new Location(locStart));
	// testing line cout << locStart.getLocDetails();
	Location locOne(locNames[1], locDescriptions[1], locExits[1], locArt[1]);
	gameLocs.push_back(new Location(locOne));
	Location locTwo(locNames[2], locDescriptions[2], locExits[2], locArt[2]);
	gameLocs.push_back(new Location(locTwo));
	Location locThree(locNames[3], locDescriptions[3], locExits[3], locArt[3]);
	gameLocs.push_back(new Location(locThree));
	Location locFour(locNames[4], locDescriptions[4], locExits[4], locArt[4]);
	gameLocs.push_back(new Location(locFour));
	Location locFive(locNames[5], locDescriptions[5], locExits[5], locArt[5]);
	gameLocs.push_back(new Location(locFive));
	Location locSix(locNames[6], locDescriptions[6], locExits[6], locArt[6]);
	gameLocs.push_back(new Location(locSix));
	Location locSeven(locNames[7], locDescriptions[7], locExits[7], locArt[7]);
	gameLocs.push_back(new Location(locSeven));
	Location locEight(locNames[8], locDescriptions[8], locExits[8], locArt[8]);
	gameLocs.push_back(new Location(locEight));
	Location locNine(locNames[9], locDescriptions[9], locExits[9], locArt[9]);
	gameLocs.push_back(new Location(locNine));
	Location locTen(locNames[10], locDescriptions[10], locExits[10], locArt[10]);
	gameLocs.push_back(new Location(locTen));
	Location locEleven(locNames[11], locDescriptions[11], locExits[11], locArt[11]);
	gameLocs.push_back(new Location(locEleven));
	Location locTwelve(locNames[12], locDescriptions[12], locExits[12], locArt[12]);
	gameLocs.push_back(new Location(locTwelve));
	Location locThirteen(locNames[13], locDescriptions[13], locExits[13], locArt[13]);
	gameLocs.push_back(new Location(locThirteen));
	Location locFourteen(locNames[14], locDescriptions[14], locExits[14], locArt[14]);
	gameLocs.push_back(new Location(locFourteen));
	Location locFifteen(locNames[15], locDescriptions[15], locExits[15], locArt[15]);
	gameLocs.push_back(new Location(locFifteen));
	Location locSixteen(locNames[16], locDescriptions[16], locExits[16], locArt[16]);
	gameLocs.push_back(new Location(locSixteen));
	Location locSeventeen(locNames[17], locDescriptions[17], locExits[17], locArt[17]);
	gameLocs.push_back(new Location(locSeventeen));
	Location locEighteen(locNames[18], locDescriptions[18], locExits[18], locArt[18]);
	gameLocs.push_back(new Location(locEighteen));
	Location locNineteen(locNames[19], locDescriptions[19], locExits[19], locArt[19]);
	gameLocs.push_back(new Location(locNineteen));
	// 	   **********************************************************
}

// playing the game functions
void movePlayer() {
	int playerLocation = gamePlayers[0].getPlayerLocation();
	// check current location of player and then move to corresponding location
	switch (playerLocation) {
	case 0:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 0;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 5;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 2;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 1;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 1:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 1;
			system("PAUSE");
			cout << "Invalid input! Please use one of the visible portals.\n\n";
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 6;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 0;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 3;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 2:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 2;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 7;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 4;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 0;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 3:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 1;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 3;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 6;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 8;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 4:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 2;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 4;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 9;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 7;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 5:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 0;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 11;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 12;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 5;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		break;
	case 6:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 1;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 6;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 10;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 3;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 7:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 2;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 7;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 4;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 10;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 8:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 8;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 13;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 11;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 3;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 9:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 9;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 14;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 4;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 12;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 10:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 10;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 15;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 7;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 6;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 11:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 5;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 11;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 15;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 8;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 12:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 15;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 12;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 9;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 5;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 13:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 8;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 16;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 13;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 18;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 14:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 9;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 17;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 19;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 14;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		break;
	case 15:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 10;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 12;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 15;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 11;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 16:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 13;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 16;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
			return;
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 17;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 18;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 17:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 14;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 17;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 19;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 16;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 18:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 18;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 19;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 16;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 13;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	case 19:
		if (playerChoice == "N" || playerChoice == "n") {
			playerLocation = 18;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "S" || playerChoice == "s") {
			playerLocation = 19;
			cout << "Invalid input! Please use one of the visible portals.\n\n";
			system("PAUSE");
		}
		else if (playerChoice == "E" || playerChoice == "e") {
			playerLocation = 14;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		else if (playerChoice == "W" || playerChoice == "w") {
			playerLocation = 17;
			gamePlayers[0].setPlayerLocation(playerLocation);
		}
		break;
	default:
		cout << "Something went wrong!";
	}
}
void displayHelp() {
	//clear screen
	system("CLS");
	displayTitle();
	// THIS CODE IS FROM WEEK 3 LAB
	// **********************************************
	//open file
	ifstream fileToRead("GameHelp.txt");
	if (fileToRead.is_open()) {
		string myItem = "";
		// read data
		while (!fileToRead.eof()) {
			getline(fileToRead, myItem);
			cout << " " << myItem << endl;
		}
	}
	// if unnable to read file
	else {
		cout << "Unable to read the data." << endl;
	}
	system("pause");
	// close file
	fileToRead.close();
	system("CLS");
	// **********************************************
}
void displayMap() {
	//clear screen
	system("CLS");
	displayTitle();
	// THIS CODE IS FROM WEEK 3 LAB
	// **********************************************
	//open file
	ifstream fileToRead("GameMap.txt");
	if (fileToRead.is_open()) {
		string myItem = "";
		// read data
		while (!fileToRead.eof()) {
			getline(fileToRead, myItem);
			cout << " " << myItem << endl;
		}
	}
	// if unnable to read file
	else {
		cout << "Unable to read the data." << endl;
	}
	system("pause");
	// close file
	fileToRead.close();
	system("CLS");
	// **********************************************
}
void hazardAction() {
	int quicksandOne = gameHazards[1]->getHazardLocation();
	int quicksandTwo = gameHazards[2]->getHazardLocation();
	int playerLocation = gamePlayers[0].getPlayerLocation();
	int newLocation = 0;

	if (playerLocation == quicksandOne) {
		newLocation = gameHazards[1]->special();
		gamePlayers[0].setPlayerLocation(newLocation);
	}
	else if (playerLocation == quicksandTwo) {
		newLocation = gameHazards[2]->special();
		gamePlayers[0].setPlayerLocation(newLocation);
	}
}
void playerAttack() {
	int playerLocation = gamePlayers[0].getPlayerLocation();
	int arrowLocation = 0;
	int witchLocation = gameHazards[0]->getHazardLocation();

	//determine arrow location
	switch (playerLocation) {
	case 0:
		if (playerChoice == "shoot n") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 5;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 2;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 1;
			break;
		}
	case 1:
		if (playerChoice == "shoot n") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 6;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 3;
			break;
		}
	case 2:
		if (playerChoice == "shoot n") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 7;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 4;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 0;
			break;
		}
	case 3:
		if (playerChoice == "shoot n") {
			arrowLocation = 1;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 6;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 8;
			break;
		}
	case 4:
		if (playerChoice == "shoot n") {
			arrowLocation = 2;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 9;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 7;
			break;
		}
	case 5:
		if (playerChoice == "shoot n") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 11;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 12;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 0;
			break;
		}
	case 6:
		if (playerChoice == "shoot n") {
			arrowLocation = 1;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 10;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 3;
			break;
		}
	case 7:
		if (playerChoice == "shoot n") {
			arrowLocation = 2;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 4;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 10;
			break;
		}
	case 8:
		if (playerChoice == "shoot n") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 13;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 11;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 3;
			break;
		}
	case 9:
		if (playerChoice == "shoot n") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 14;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 4;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 12;
			break;
		}
	case 10:
		if (playerChoice == "shoot n") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 15;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 7;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 6;
			break;
		}
	case 11:
		if (playerChoice == "shoot n") {
			arrowLocation = 5;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 15;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 8;
			break;
		}
	case 12:
		if (playerChoice == "shoot n") {
			arrowLocation = 15;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 9;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 5;
			break;
		}
	case 13:
		if (playerChoice == "shoot n") {
			arrowLocation = 8;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 16;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 18;
			break;
		}
	case 14:
		if (playerChoice == "shoot n") {
			arrowLocation = 9;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 17;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 19;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 0;
			break;
		}
	case 15:
		if (playerChoice == "shoot n") {
			arrowLocation = 10;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 12;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 11;
			break;
		}
	case 16:
		if (playerChoice == "shoot n") {
			arrowLocation = 13;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 17;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 18;
			break;
		}
	case 17:
		if (playerChoice == "shoot n") {
			arrowLocation = 14;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 19;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 16;
			break;
		}
	case 18:
		if (playerChoice == "shoot n") {
			arrowLocation = 18;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 19;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 16;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 13;
			break;
		}
	case 19:
		if (playerChoice == "shoot n") {
			arrowLocation = 18;
			break;
		}
		if (playerChoice == "shoot s") {
			arrowLocation = 0;
			break;
		}
		if (playerChoice == "shoot e") {
			arrowLocation = 14;
			break;
		}
		if (playerChoice == "shoot w") {
			arrowLocation = 17;
			break;
		}
	default:
		cout << " Something went wrong!";
		// if hit
		// if miss
	}

	if (arrowLocation == witchLocation) {
		attackOutcome = 1;
		cout << "The sky lights up as the power of the staff hits the witch! She crumbles to the ground and you feel rejuvinated as your lifeforce returns to you.\n\n";
		system("PAUSE");
	}
	else if (arrowLocation != witchLocation) {
		attackOutcome = 0;
		cout << " It appears you missed... I wonder if the witch heard that?\n\n";
		system("PAUSE");
		// determine if witch is to move
		int chance = rand() % 4 + 1;
		// witch does move
		if (chance == 1 || chance == 2 || chance == 3) {
			int newLocation = gameHazards[0]->special();
			gameHazards[0]->setHazardLocation(newLocation);
			cout << "\n Unsuprisingly, the witch heard your attack! She's most likely moved on now...\n\n";
			system("PAUSE");
		}
		// witch doesn't move
		else if (chance == 4) {
			cout << "\n Somehow, the witch didn't hear your attack! A mystery that one...\n\n";
			system("PAUSE");
		}
	}
}
void getHint() {
	int hazardClose = 0; // 0 for no, 1 for yes
	for (int i = 0; i < gameHazards.size(); i++) {
		int hazardLocation = gameHazards[i]->getHazardLocation();
		int playerLocation = gamePlayers[0].getPlayerLocation();
		//check if there is a hazard nearby
		switch (hazardLocation) {
		case 1:
			if (playerLocation == 3 || playerLocation == 6 || playerLocation == 0) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 2:
			if (playerLocation == 0 || playerLocation == 7 || playerLocation == 4) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 3:
			if (playerLocation == 1 || playerLocation == 6 || playerLocation == 8) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 4:
			if (playerLocation == 2 || playerLocation == 7 || playerLocation == 9) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 5:
			if (playerLocation == 0 || playerLocation == 11 || playerLocation == 12) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 6:
			if (playerLocation == 1 || playerLocation == 3 || playerLocation == 10) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 7:
			if (playerLocation == 2 || playerLocation == 4 || playerLocation == 10) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 8:
			if (playerLocation == 3 || playerLocation == 11 || playerLocation == 13) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 9:
			if (playerLocation == 4 || playerLocation == 12 || playerLocation == 14) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 10:
			if (playerLocation == 6 || playerLocation == 15 || playerLocation == 7) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 11:
			if (playerLocation == 5 || playerLocation == 8 || playerLocation == 15) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 12:
			if (playerLocation == 5 || playerLocation == 15 || playerLocation == 9) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 13:
			if (playerLocation == 8 || playerLocation == 16 || playerLocation == 18) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 14:
			if (playerLocation == 9 || playerLocation == 17 || playerLocation == 19) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 15:
			if (playerLocation == 10 || playerLocation == 11 || playerLocation == 12) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 16:
			if (playerLocation == 13 || playerLocation == 17 || playerLocation == 18) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 17:
			if (playerLocation == 14 || playerLocation == 16 || playerLocation == 19) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
		case 18:
			if (playerLocation == 13 || playerLocation == 16 || playerLocation == 19) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		case 19:
			if (playerLocation == 14 || playerLocation == 17 || playerLocation == 18) {
				cout << gameHazards[i]->getHazardHint();
				hazardClose = 1;
			}
			break;
		default:
			cout << "Something went wrong!";
		}
	}
	if (hazardClose == 0) {
		cout << "\n\n Nothing seems out of place.";
	}
}
string checkGameStatus() {
	// get all of the current information to test
	int playerLocation = gamePlayers[0].getPlayerLocation();
	int quicksandOne = gameHazards[1]->getHazardLocation();
	int quicksandTwo = gameHazards[2]->getHazardLocation();
	int witch = gameHazards[0]->getHazardLocation();
	int cryptOne = gameHazards[3]->getHazardLocation();
	int cryptTwo = gameHazards[4]->getHazardLocation();
	int numAttacks = gamePlayers[0].getNumAttacks();
	int numTurns = gamePlayers[0].getNumTurns();
	string gameStatus = "ongoing";
	// check if the player has hit the witch
	if (attackOutcome == 1) {
		gameStatus = "won!";
	}
	// check if the witch is in the same location as player
	else if (playerLocation == witch) {
		cout << gameHazards[0]->getHazardDetails();
		gameStatus = "lost!";
		deathCause = " You ran straight into the witch!";
		system("PAUSE");
	}
	// check for quicksand, move player if so
	else if (playerLocation == quicksandOne || playerLocation == quicksandTwo) {
		// both quicksand are the same so can use either description
		cout << gameHazards[1]->getHazardDetails();
		gameStatus = "ongoing";
		hazardAction();
		system("PAUSE");
	}
	// check for corrupted crypt
	else if (playerLocation == cryptOne || playerLocation == cryptTwo) {
		// both crypts are the same so can use either description
		cout << gameHazards[3]->getHazardDetails();
		gameStatus = "lost!";
		deathCause = " You stumbled across a Corrupted Crypt!";
		system("PAUSE");
	}
	// check if number of attacks remaining = 0
	else if (numAttacks == 0) {
		cout << " Oh no! It appears you've used the staff too many times and it's become unstable!\n\n";
		gameStatus = "lost!";
		deathCause = " You ran out of attacks!";
		system("PAUSE");
	}
	// check if number of turns remaining = 0
	else if (numTurns == 0) {
		cout << "Oh no! That last portal was too much for your weak body to handle and you feel yourself crumble to the ground. It seems your time is up!\n\n";
		gameStatus = "lost!";
		deathCause = " Your lifeforce was depleted! (You ran out of turns)";
		system("PAUSE");
	}
	return gameStatus;
}
string askForString(string question) {
	// CODE FROM WEEK 3 LAB
	// get user input
	string userInput = "";
	while (userInput == "") {
		cout << "\n " + question;
		cin.clear();
		getline(cin, userInput);
	}
	return userInput;
}

// end game
void displayStats(int score, string gameStatus) {
	displayTitle();
	cout << " And the game is finished! Here's how you did: ";
	cout << "\n\n You " << gameStatus;
	cout << "\n You had a total score of: " << score;
	cout << "\n\n With: \n" << gamePlayers[0].getPlayerDetails() << "\n\n";
	if (gameStatus == "lost!") {
		cout << "\n Cause of loss: " << deathCause << "\n\n";
	}
}
void deleteHazards() {
	// delete all of the hazards
	// THIS CODE HAS BEEN ADAPTED FROM WEEK 10 LAB
	// 	   **********************************************************
	for (int i = gameHazards.size() - 1; i >= 0; i--) {
		// testing line cout << "Hazard Deleted";
		delete gameHazards[i];
		gameHazards[i] = nullptr;
	}
	// double check entirely empty
	gameHazards.clear();
	// 	   **********************************************************
}

// extra functionality
int setMoveWitch() {
	// witch to move after a random number of turns between 3-5
	moveNumber = rand() % 3 + 3;
	// testing line cout << moveNumber;
	return moveNumber;
}
int setDifficulty() {
	system("CLS");
	displayTitle();
	cout << "\n Before you leave... I have to ask a few questions...";
	int difficulty = 0;
	// select the difficulty level for the game
	string question = "What level of experience do you think will be required for this journey? Please enter in all lowercase. [ novice, apprentice or adept ] ";
	string playerAnswer = "";

	//assign difficulty
	while (difficulty == 0) {
		system("CLS");
		displayTitle();
		playerAnswer = askForString(question);
		if (playerAnswer == "novice") {
			cout << " You have selected NOVICE difficulty\n\n";
			system("PAUSE");
			difficulty = 1;
			return difficulty;
		}
		else if (playerAnswer == "apprentice") {
			cout << " You have selected APPRENTICE difficulty\n\n";
			system("PAUSE");
			return difficulty;
			difficulty = 2;
		}
		else if (playerAnswer == "adept") {
			cout << " You have selected ADEPT difficulty\n\n";
			system("PAUSE");
			difficulty = 3;
			return difficulty;
		}
		else {
			system("CLS");
			displayTitle();
			cout << "\n Either something went wrong or you didn't choose a valid option! Please try again\n\n";
			system("PAUSE");
		}
	}

}
int determineScore(int difficulty, string gameStatus) {
	// get variables that will be tested
	int turns = gamePlayers[0].getNumTurns();
	int attacks = gamePlayers[0].getNumAttacks();

	int score = 0; // total score
	int score1 = 0; // from difficulty
	int score2 = 0; // from turns
	int score3 = 0; // from attacks

	// check level of difficulty
	switch (difficulty) {
	case 1:
		score1 = 0;
		break;
	case 2:
		score1 = 2;
		break;
	case 3:
		score1 = 5;
		break;
	default:
		cout << "Something went wrong!";
	}
	// check number of turns remaining 
	if (turns > 4) {
		score2 = 10;
	}
	else if (turns > 6) {
		score2 = 6;
	}
	else if (turns > 8) {
		score2 = 3;
	}
	else {
		score2 = 0;
	}
	// check number of attacks remaining
	switch (attacks) {
	case 1:
		score3 = 0;
		break;
	case 2:
		score3 = 1;
		break;
	case 3:
		break;
		score3 = 2;
	case 4:
		score3 = 3;
		break;
	deafult:
		cout << "Something went wrong! attacks";
	}
	// if the game is lost, score will be 0
	if (gameStatus == "lost!") {
		score = 0;
	}
	// calculate total score
	else {
		score = score1 + score2 + score3;
	}
	return score;
}
void moveWitch(int difficulty) {
	// check if the number has reached the set number of turns to move after
	int turnsLeft = gamePlayers[0].getNumTurns();
	int turnsPast = 0;
	int newLocation = 0;
	// based on difficulty
	switch (difficulty) {
	case 1:
		// get the number of turns passed
		turnsPast = 12 - turnsLeft;
		// check if number of turns passed is equal to num to move witch, if equal to move witch
		if (turnsPast == moveNumber) {
			// move witch
			newLocation = gameHazards[0]->special();
			gameHazards[0]->setHazardLocation(newLocation);
			cout << " In the time you've taken, the witch appears to have moved! You better find her before she moves again...\n\n";
			system("PAUSE");
			// set new number of turns to move
			setMoveWitch();
		}
		// if it doesnt equal num, continue as normal
		else {
			return;
		}
		break;
	case 2:
		turnsPast = 10 - turnsLeft;
		if (turnsPast == moveNumber) {
			newLocation = gameHazards[0]->special();
			gameHazards[0]->setHazardLocation(newLocation);
			cout << " In the time you've taken, the witch appears to have moved! You better find her before she moves again...\n";
			system("PAUSE");
			setMoveWitch();
		}
		else {
			return;
		}
		break;
	case 3:
		turnsPast = 8 - turnsLeft;
		if (turnsPast == moveNumber) {
			newLocation = gameHazards[0]->special();
			gameHazards[0]->setHazardLocation(newLocation);
			cout << " In the time you've taken, the witch appears to have moved! You better find her before she moves again...\n";
			system("PAUSE");
			setMoveWitch();
		}
		else {
			return;
		}
		break;
	default:
		cout << " Something went wrong!";
	}
}