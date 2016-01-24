/*
 * CodingTable.h
 *
 *  Created on: Jan 4, 2016
 *      Author: erolh
 */

#ifndef CODINGTABLE_H_
#define CODINGTABLE_H_

#include <iostream>
#include <string>

#include "BitString.h"
#include "HuffmanNodes.h"


using namespace std;

class CodingTable {
	static const int ASCII_SIZE = 256;
	static const int ASCII_OFFSET = 128;
	BitString table[ASCII_SIZE];
	void codingTableHelper(const HuffmanNode& root,BitString& currentCode);
public:
	CodingTable(){}
	CodingTable(const HuffmanNode& root);
	BitString encode(const string& toEncode) const;

	friend ostream& operator<<(ostream& os,const CodingTable& toPrint);
};

#endif /* CODINGTABLE_H_ */
