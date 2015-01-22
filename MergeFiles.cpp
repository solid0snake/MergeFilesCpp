/*
* MergeFiles.cpp
* By Pedro Garate on 01/21/2015
* Description: Given three text files, each of which contains a
*              sorted list of integers (one integer per line)
*              in ascending order, this program merges
*              these input files into another file in which all
*              the numbers remain their sorted order. Finally,
*              it informs the user the name of the merged file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// return true if file has more input.
bool hasMore(ifstream& inFile, int& num);
// print number from input file to output file and return
// true if file has more input.
bool output(ofstream& outFile, ifstream& inFile, int& num);

int main() {
	string fileName1, fileName2, fileName3;
	string outFile = "MergedFile.txt"; // name of output file
	ifstream inFile1, inFile2, inFile3;
	ofstream outStream;
	////////////////////////////////////////////////////////////

	cout << "FILE MERGESORT:" << endl;
	cout << "Input the name of three files, each of which contains"
		" a sorted list\nof integers (one integer per line) in"
		" non-decreasing order. This\nprogram will merge these "
		"input files into another file in which all\nthe "
		"numbers remain their sorted order. Finally, it will "
		"inform you\nthe name of the merged file. "
		"Keep in mind that the three input files\nmust be "
		"located in the same folder as this program.\n\n";
	//disclaimer
	cout << "Enter names without file extensions. This program "
		"will append\n\".txt\" at the end.\n";

	cout << "Please enter the name of the first file:\n";
	cin >> fileName1;
	inFile1.open(fileName1.append(".txt").c_str());
	// convert to c_string, append ".txt" and open.

	cout << "Please enter the name of the second file:\n";
	cin >> fileName2;
	inFile2.open(fileName2.append(".txt").c_str());
	// convert to c_string, append ".txt" and open.

	cout << "Please enter the name of the third file:\n";
	cin >> fileName3;
	inFile3.open(fileName3.append(".txt").c_str());
	// convert to c_string, append ".txt" and open.

	outStream.open(outFile.c_str());
	// convert to c_string and open.

	int num1, num2, num3;
	bool hasMore1, hasMore2, hasMore3;

	hasMore1 = hasMore(inFile1, num1);
	hasMore2 = hasMore(inFile2, num2);
	hasMore3 = hasMore(inFile3, num3);

	// case when all three files have input still.
	while (hasMore1 && hasMore2 && hasMore3) {
		if (num1 < num2) {
			if (num1 < num3)
				hasMore1 = output(outStream, inFile1, num1);
			else
				hasMore3 = output(outStream, inFile3, num3);
		}// end if
		else if (num2 < num3)
			hasMore2 = output(outStream, inFile2, num2);
		else
			hasMore3 = output(outStream, inFile3, num3);
	}// end while

	// case when only file1 and file2 have input still
	while (hasMore1 && hasMore2) {
		if (num1 < num2)
			hasMore1 = output(outStream, inFile1, num1);
		else hasMore2 = output(outStream, inFile2, num2);
	}// end while

	// case when only file1 and file3 have input still
	while (hasMore1 && hasMore3) {
		if (num1 < num3)
			hasMore1 = output(outStream, inFile1, num1);
		else hasMore3 = output(outStream, inFile3, num3);
	}// end while

	// case when only file2 and file3 have input still
	while (hasMore2 && hasMore3) {
		if (num2 < num3)
			hasMore2 = output(outStream, inFile2, num2);
		else hasMore3 = output(outStream, inFile3, num3);
	}// end while

	// case when only file1 has input still
	while (hasMore1) {
		hasMore1 = output(outStream, inFile1, num1);
	}// end while

	// case when only file2 has input still
	while (hasMore2) {
		hasMore2 = output(outStream, inFile2, num2);
	}// end while

	// case when only file3 has input still
	while (hasMore3) {
		hasMore3 = output(outStream, inFile3, num3);
	}// end while

	outStream << endl;

	// close all inputs and outputs.
	inFile1.close();
	inFile2.close();
	inFile3.close();
	outStream.close();

	cout << "\nMerge complete!!!\n";
	cout << "Your file is in the same folder as your input "
		"files.\nIts name is \"" << outFile << "\".\n";
	return 0;
}// end main

// return true if file has more input.
bool hasMore(ifstream& inFile, int& num) {
	if (inFile >> num) return true;
	else return false;
}// end hasMore

// print number from input file to output file and return
// true if file has more input.
bool output(ofstream& outFile, ifstream& inFile, int& num) {
	outFile << num << "\r\n";
	return hasMore(inFile, num);
}// end output
