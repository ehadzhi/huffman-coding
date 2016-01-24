/*
 * FrequencyTable.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: erolh
 */

#include "FrequencyTable.h"

FrequencyTable::FrequencyTable(const string& toAnalyze) {
	vector<unsigned long> freqTable(ASCII_SIZE, 0);

	for (int index = 0; index < toAnalyze.size(); index++) {
		freqTable.at(toAnalyze.at(index) + ASCII_OFFSET)++;
	}

	LeafNode* node;
	for (int index = 0; index < ASCII_SIZE; index++) {
		if (freqTable.at(index) <= 0) {
			continue;
		}
		node = new LeafNode(freqTable.at(index), index - ASCII_OFFSET);
		nodes.push_back(node);
	}
}

ostream& operator <<(ostream& os, const FrequencyTable& freqTable) {
	for ( auto &node : freqTable.nodes ) {
		os<<"Char : "<<node->getValue()
		<<" Freq : "<<node->getWeight()<<endl;
	}
	return os<<endl;
}

vector<HuffmanNode*> FrequencyTable::getNodes() const{
	return this->nodes;
}

