#pragma once
#include <iostream>
using namespace std;
#include <string>;
#include "MemoryMatchGame.h"
#include <fstream>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>




class MemoryMatchGame
{
private:
	int theme;
	int level;
	int speed;
	int answerRow1;
	int answerColoumn1;
	int answerRow2;
	int answerColoumn2;
	string name;
	string themeWords[50]; //- load from file into this arrray
	string rR[50];
	string answerArray[8][8];//load 8, 18, or 32 words twice into this array, depending on game size selected
	string gamePlayArray[8][8]; //– Game play and display array
	string sC[8][8];

public:
	void fileRead(string themeChoose);

	void start();

	void chooseTheme();

	void chooseLevel();

	void chooseSpeed();

	void shuffleArray(string rR[50]);

	void dispCards();

	void printCards();

	void cardLevel();

	void shuffleCards(string sC[8][8]);

	void inputAnswer();

	void match();
	


};

