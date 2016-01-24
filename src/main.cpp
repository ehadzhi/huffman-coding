/*
 * main.cpp
 *
 *  Created on: Dec 12, 2015
 *      Author: erolh
 */

#include <iostream>
#include <string>

using namespace std;
#include"FrequencyTable.h"
#include"HuffmanTree.h"
#include"CodingTable.h"
#include"BitString.h"
#include <sstream>
#include <fstream>

void outputCompression(const BitString& compressed,
		const string& uncompresssed) {
	double compressionPercent = (((double) (compressed.size()))
			/ (uncompresssed.size() * 8)) * 100;
	cout << "Compresion is " << compressionPercent << " %" << endl;
}

void huffmanDemo(const string& demoString) {
	HuffmanTree tree(demoString);
	BitString bit = tree.encode(demoString);
	string byte = tree.encodeToByte(demoString);
	cout << "tree :" << endl << tree << endl;
	cout << "bit code :" << endl << bit << endl;
	cout << "byte code :" << endl << byte << endl;
	cout << "decoded :" << endl << tree.decode(tree.encode(demoString)) << endl;
	outputCompression(bit, demoString);
}

string readFile(const char* inFileName) {
	ifstream inFile;
	inFile.open(inFileName);

	stringstream strStream;
	strStream << inFile.rdbuf();
	string str = strStream.str();

	return str;
}

int main() {
	string toTest = "This thing better work."; // readFile("The.Hateful.Eight.2015.txt");
	huffmanDemo(toTest);
	return 0;
}

