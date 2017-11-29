// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <iomanip>

#define NUMBER_OF_COL 6

using namespace std;



// TODO: reference additional headers your program requires here
class NYData {
private:
	int counter;
	int numOfGame;
	string date;
	vector<string> gameInfo;

public:
	NYData(int numOfGame = 0, string date = "");
	void setData(ifstream& fin);
	
	int getNumOfGame(void) { return numOfGame; };


	void printVec(vector<string> tempVec);

	void printData(ofstream& fout);
	
	vector<string> colReturn(int col);

	string mostUnclaimFirst(void);

	~NYData(void);
};