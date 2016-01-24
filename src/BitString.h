/*
 * BitString.h
 *
 *  Created on: Jan 8, 2016
 *      Author: erolh
 */

#ifndef BITSTRING_H_
#define BITSTRING_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BitString {
	vector<bool> container;
public:
	void pushBack(bool val);
	bool popBack();
	int size() const;
	void append(const BitString& toAppend);
	string toString() const;
	friend ostream& operator<<(ostream& os, const BitString& toPrint);
	vector<bool>::const_iterator getBegin() const;
	vector<bool>::const_iterator getEnd() const;
};

#endif /* BITSTRING_H_ */
