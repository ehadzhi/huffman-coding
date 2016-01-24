/*
 * HuffmanTree.h
 *
 *  Created on: Dec 27, 2015
 *      Author: erolh
 */

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include <iostream>
#include <string>

#include "CodingTable.h"
#include "FrequencyTable.h"

using namespace std;

class HuffmanTree {
	HuffmanNode* root;
	HuffmanNode* buildHuffmanTree(const FrequencyTable& freqTable);
	CodingTable codingTable;
public:
	HuffmanTree(const FrequencyTable&);
	string decode(const BitString&) const;
	string encodeToByte(const string&) const;
	BitString encode(const string&) const;
	friend ostream& operator<<(ostream&, const HuffmanTree&);
};

#endif /* HUFFMANTREE_H_ */
