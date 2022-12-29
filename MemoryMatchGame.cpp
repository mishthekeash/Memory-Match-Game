#include "MemoryMatchGame.h"
#include <iostream>
using namespace std;
#include <string>;
#include <fstream>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>





void MemoryMatchGame::chooseTheme() {
	bool flag;
	flag = false;
	while (flag == false) {
		cout << "Choose game theme: select either 1, 2, 3 " << endl;
		cout << "1 elements" << endl;
		cout << "2 trees" << endl;
		cout << "3 countries" << endl;
		cin >> theme;
		switch (theme) {
		case 1: name = "elements.txt"; break;
		case 2: name = "Week12MichaelShkolnikTrees.txt"; break;
		case 3: name = "Week12MichaelShkolnikCountries.txt"; break;


		}
		if (theme==1 || theme==2 || theme==3) {
			flag = true;
		}
		else {
			cout << "choose a correct theme" << endl;
		}
	}//end while
}

void MemoryMatchGame::chooseLevel() {
	bool flag;
	flag = false;
	while (flag == false) {

		cout << "Choose level type: select either 4, 6, 8 " << endl;
		cout << "4 x 4 grid(Easy)" << endl;
		cout << "6 x 6 grid(Moderate)" << endl;
		cout << "8 X 8 grid(Difficult)" << endl;
		cin	>> level;
		if (level ==4 || level ==6 || level ==8) {
			flag = true;
		}
		else {
			cout << "choose a correct level" << endl;
		}
	}//while end
}

void MemoryMatchGame::chooseSpeed() {
	bool flag;
	flag = false;
	while (flag == false) {
		cout << "choose game speed: select either 2, 4, 6, " << endl;
		cout << "2 seconds(Difficult)" << endl;
		cout << "4 seconds(Moderate)" << endl;
		cout << "6 seconds(Easy)" << endl;
		cin >> speed;

		if (speed == 2 || speed == 4 || speed == 6) {
			flag = true;
		}
		else {
			cout << "choose a correct speed" << endl;
		}

	}
}
//readfile
void MemoryMatchGame::fileRead(string themeChoose) {
	ifstream myfile;

	myfile.open(themeChoose);	//1 step
	if (!myfile) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		
		int i=0;
		for (int i = 0; i < 50; i++) {
			myfile >> themeWords[i];	//reading file
			//cout << themeWords[i]<<endl;

		}
		
	}
	// Close the file
	myfile.close();  //3 step



}


void MemoryMatchGame::shuffleArray(string rR[50]) {
	
	srand(time(NULL));
	for (int i = 50-1; i >= 1; i--) {
		int j = rand()%(i+1);
		string temp = rR[j];
		rR[j] = rR[i];
		rR[i] = temp;
		
		
		
	}
/*
	for (int i = 0; i < 50; i++) {

		cout << rR[i]<<endl;
	}
	*/

}

void MemoryMatchGame::dispCards() {
	int v = 0;
	for (int i = 0; i < level; i++) {
		


		for (int j = 0; j < level; j++) {
		
			//cout << j + 1 << " ";
			gamePlayArray[i][j] = "term";
			

		}

}


}


void MemoryMatchGame::printCards() {
	

	
		switch (level) {
		case 8:
		
			cout << "[ ][1][2] [3][4][5][6][7][8]"<<endl;
			for (int i = 0; i < 8; i++) {
				switch (i) {
				case 0:
					cout << "[1]";
					break;
				case 1:
					cout << "[2]";
					break;
				case 2:
					cout << "[3]";
					break;
				case 3:
					cout << "[4]";
					break;
				case 4:
					cout << "[5]";
					break;
				case 5:
					cout << "[6]";
					break;

				case 6:
				
					cout << "[7]";
					break;
				
				case 7:
					cout << "[8]";
					break;
				}
				
				for (int j = 0; j < 8; j++) {
					cout << "[";
					cout << gamePlayArray[i][j];
					cout << "]";
				}
				cout << endl;
			}
			break;
		case 6:
			cout << "[ ][1 ][2 ][3 ][4 ][5 ][6 ]"<<endl;
			for (int i = 0; i < 6; i++) {
				switch (i) {
				case 0:
					cout << "[1]";
					break;
				case 1:
					cout << "[2]";
					break;
				case 2:
					cout << "[3]";
					break;
				case 3:
					cout << "[4]";
					break;
				case 4:
					cout << "[5]";
					break;
				case 5:
					cout << "[6]";
					break;
				}
				for (int j = 0; j < 6; j++) {
					cout << "[";
					cout << gamePlayArray[i][j];
					cout << "]";
				}
				cout << endl;
			}
			break;
		case 4:
			cout << "[ ][1 ][2 ][3 ][4 ]"<<endl;
			for (int i = 0; i < 4; i++) {
				switch (i) {
				case 0:
					cout << "[1]";
					break;
				case 1:
					cout << "[2]";
					break;
				case 2:
					cout << "[3]";
					break;
				case 3:
					cout << "[4]";
					break;
				}
				for (int j = 0; j < 4; j++) {
					cout << "[";
					cout << gamePlayArray[i][j];
					cout << "]";
				}
				cout << endl;
			}
			break;
		}
	







	/*
	for (int i = 0; i < level; i++) {
		cout<< setw(8) <<i+1 ;

	}
	cout << endl;
	cout << endl;

	for (int i = 0; i < level; i++) {
		for (int j = 0; j < level; j++) {
			cout <<gamePlayArray[i][j] << (" _|_");
		
		}
		cout << ("") << endl;

	}*/



}
////sorts 50 words into 16 , 36 , 64 
void MemoryMatchGame::cardLevel() {
	int cardsHalf;
	cardsHalf = (level*level) / 2;
	

	int cardCount = 0;
	while (cardsHalf != 0) {
		for (int i = 0; i < level / 2; i++) {
			for (int j = 0; j < level ; j++) {
				answerArray[i][j] = themeWords[cardCount];
				cardCount++;
				cardsHalf--;
			}

		}
	}
	cardCount--;//return to end of list of cards
	while (cardCount != -1) {
		for (int i = level / 2; i < level; i++) {
			for (int j = 0; j < level; j++) {
				answerArray[i][j] = themeWords[cardCount];
				cardCount--;
				
			}

		}
	}
	
}

void MemoryMatchGame::shuffleCards(string sC[8][8]) {

	srand(time(NULL));
	for (int i = 0; i < level; i++) {
		for (int j = 0; j < level; j++) {
			int x = rand() % (level);
			int y = rand() % (level);
			string temp = sC[i][j];
			sC[i][j] = sC[x][y];
			sC[x][y] = temp;


		}

	}


}
//answerArray is now ready

void MemoryMatchGame::inputAnswer() {
	int game = 0;
	int pairs=0;
	int neededTerms=(level*level)/2;

	

	while (game == 0) {
		cout << "enter two cards to match. Ex 1 3 and 4 2 , go by row and coloumn" << endl;

		cout << "enter row: then enter column" << endl;
		cin >> answerRow1 >> answerColoumn1;
		gamePlayArray[answerRow1 - 1][answerColoumn1 - 1] = answerArray[answerRow1 - 1][answerColoumn1 - 1];
		
		printCards();

		



		cout << "now enter the 2nd cards cordinates: row , column" << endl;
		cin >> answerRow2 >> answerColoumn2;
		gamePlayArray[answerRow2 - 1][answerColoumn2 - 1] = answerArray[answerRow2 - 1][answerColoumn2 - 1];
		
		
		printCards();

		

		if (answerArray[answerRow1 - 1][answerColoumn1 - 1] == answerArray[answerRow2 - 1][answerColoumn2 - 1]) {
			cout << "Its a match!" << endl;
			pairs++;
			if (pairs == neededTerms) {
				cout << "You win!";
				game = 1;
			}
			Sleep(speed * 1000);



		}

		else {
			
			cout << "wrong match!" << endl;
			gamePlayArray[answerRow1 - 1][answerColoumn1 - 1] = "term";
			gamePlayArray[answerRow2 - 1][answerColoumn2 - 1] = "term";
			Sleep(speed * 1000);
			system("cls");//clears board after chosen speeed
			cout << "try again!" << endl;
			printCards();
		}


		//cout << answerArray[answerRow1][answerColoumn1] << endl;

	//cout << answerArray[answerRow2][answerColoumn2];

	}
}

void MemoryMatchGame::match() {
	



}






void MemoryMatchGame::start() {

	chooseTheme();
	chooseLevel();
	chooseSpeed();
	fileRead(name);
	//themeWords = shuffleArray(themeWords);
	shuffleArray(themeWords);
	cardLevel();
	dispCards();
	printCards();
	shuffleCards(answerArray);
	inputAnswer();
	match();
}

/*
switch (level) {
case 4:	for (int i = 0; i < 7; i++) {
	for (int j = 0; j < 7; j++) {
		answerArray[i][j] = themeWords[i];
	}

}break;

case 6:	for (int i = 0; i < 7; i++) {
	for (int j = 0; j < 7; j++) {
		answerArray[i][j] = themeWords[i];	break;

case 8:	for (int i = 0; i < 7; i++) {
	for (int j = 0; j < 7; j++) {
		answerArray[i][j] = themeWords[i];	break;

default:	break;
	}
	*/
