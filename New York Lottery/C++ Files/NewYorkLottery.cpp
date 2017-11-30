// NewYorkLottery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{

	ifstream fin;
	ofstream fout;
	string line;

	fin.open("testing.txt");
	fout.open("result.txt");

	NYData myData;
	
	myData.setData(fin);

	myData.printVec(myData.colReturn(5));

	myData.printData(fout);
	

	fin.close();
	fout.close();
    return 0;
}

