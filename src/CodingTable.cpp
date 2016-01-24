/*
 * CodingTable.cpp
 *
 *  Created on: Jan 4, 2016
 *      Author: erolh
 */

#include "CodingTable.h"

void CodingTable::codingTableHelper(const HuffmanNode& root,
		BitString& currentCode) {

	if (root.isLeaf()) {
		this->table[(int) root.getValue() + ASCII_OFFSET] = currentCode;
	} else {

		currentCode.pushBack(0);
		codingTableHelper(*(root.getLeft()), currentCode);
		currentCode.popBack();

		currentCode.pushBack(1);
		codingTableHelper(*(root.getRight()), currentCode);
		currentCode.popBack();
	}
}

CodingTable::CodingTable(const HuffmanNode& root) {
	BitString workCode;
	codingTableHelper(root, workCode);
}

ostream& operator<<(ostream& os, const CodingTable& toPrint) {
	for (int i = 0; i < toPrint.ASCII_SIZE; i++) {
		if (toPrint.table[i].size() > 0)
			os << (char) (i + 128) << " - " << toPrint.table[i] << endl;
	}
	return os;
}

BitString CodingTable::encode(const string& toEncode) const {
	BitString toReturn;
	for (int index = 0; index < toEncode.size(); index++) {
		toReturn.append(table[(int) toEncode.at(index) + ASCII_OFFSET]);
	}
	return toReturn;
}
