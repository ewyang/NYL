// stdafx.cpp : source file that includes just the standard includes
// $safeprojectname$.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

NYData::NYData(int aNumOfGame, string aDate) {
	numOfGame = aNumOfGame;
	date = aDate;
}

void NYData::setData(ifstream& fin) {
	
	string temp;
	int counter = 0;
	deque<string> data;

	fin.ignore(100, '\n');

	fin >> date;

	for (int i = 0; i < 8; i++) {
		fin.ignore(100, '\n');
	}

	while (!fin.eof()) {

		getline(fin,temp);

		if (date == temp){
			break;
		}
	
		data.push_back(temp);
	}

	while (!data.empty()) {
		gameInfo.push_back(data.front());
		data.pop_front();
		counter++;
	}

	numOfGame = counter / NUMBER_OF_COL;
}

void NYData::printData(ofstream& fout) {

	int counter = 0;
	
	fout << date << endl;
	fout << left << setw(30) << "Game Title"
		<< setw(20) << "Game #"
		<< setw(20) << "Top Prize"
		<< setw(20) << "Unclaimed"
		<< setw(20) << "2nd Prize"
		<< setw(20) << "Unclaimed" << endl;

	while(counter != gameInfo.size()){
		
		if (counter == 0) {
			fout << setw(30);
		}

		if (counter % NUMBER_OF_COL == 0 && counter != 0){
			fout << endl;
			fout << left << setw(30);
		}

		fout << gameInfo[counter];
		fout << setw(20);

		counter++;
	}
}

vector<string> NYData::colReturn(int col) {

	vector<string> myVec;
	string temp;
	int counter = 0;

	if (col < 0 || col > 5) {
		cout << "Please insert value between 0-5" << endl;
		return myVec;
	}

	for (vector<string>::iterator it = gameInfo.begin()+col; it < gameInfo.end(); it+= NUMBER_OF_COL) {
		counter += NUMBER_OF_COL;

		if (counter >= gameInfo.size()) {

			if (it < gameInfo.end()) {
				myVec.push_back(*it);
				break;
			}
		}
		else {
			myVec.push_back(*it);
		}
	}

	return myVec;
}

void NYData::printVec(vector<string> tempVec) {

	for (vector<string>::iterator it = tempVec.begin(); it != tempVec.end(); it++) {
		cout << *it << endl;
	}
}

string NYData::mostUnclaimFirst(void) {

	return "hello";

}
NYData::~NYData(void) {
	gameInfo.clear();
}