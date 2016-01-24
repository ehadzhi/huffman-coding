/*
 * BitString.cpp
 *
 *  Created on: Jan 8, 2016
 *      Author: erolh
 */

#include "BitString.h"

#include <cmath>

void BitString::pushBack(bool val) {
	container.push_back(val);
}

bool BitString::popBack() {
	if (container.size() > 0) {
		container.pop_back();
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const BitString& toPrint) {
	vector<bool>::const_iterator iter = toPrint.container.begin();
	int counter = 0;
	while (iter != toPrint.container.end()) {
		os << *(iter);
		if (counter == 7)
			os << " ";
		counter++;
		counter %= 8;
		iter++;
	}
	return os;
}

int BitString::size() const {
	return container.size();
}

void BitString::append(const BitString& toAppend) {
	vector<bool>::const_iterator toIter = toAppend.container.begin();

	while (toIter != toAppend.container.end()) {
		container.push_back(*(toIter));
		toIter++;
	}
}

vector<bool>::const_iterator BitString::getBegin() const {
	return container.begin();
}

string BitString::toString() const {
	string toReturn;
	vector<bool>::const_iterator iter = container.begin();
	int currentByteCode;
	while (iter != container.end()) {
		currentByteCode = 0;
		for (int i = 7; i >= 0 && iter != container.end(); i--) {
			currentByteCode += (*iter) * pow(2, i);
			iter++;
		}
		toReturn.append(to_string(currentByteCode).append(" "));
		//toReturn.push_back(currentByteCode);

	}
	return toReturn;
}

vector<bool>::const_iterator BitString::getEnd() const {
	return container.end();
}
