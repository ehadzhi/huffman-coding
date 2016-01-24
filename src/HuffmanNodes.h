/*
 * HuffmanNode.h
 *
 *  Created on: Dec 26, 2015
 *      Author: erolh
 */

#ifndef HUFFMANNODES_H_
#define HUFFMANNODES_H_

#include "KeyValPair.h"

class HuffmanNode {
public:
	virtual ~HuffmanNode() {
	}
	virtual int getWeight() const = 0;				 // Return frequency
	virtual bool isLeaf() const {   					 // Determine type
		return false;
	}
	virtual HuffmanNode* getLeft() const {         // Get left
		return nullptr;
	}
	virtual void setLeft(HuffmanNode*) {			 // Set left
		return;
	}
	virtual HuffmanNode* getRight() const {		 // Get right
		return nullptr;
	}
	virtual void setRight(HuffmanNode*) { 		 // Set right
		return;
	}
	virtual char getValue() const = 0;			 // get value if it has such
};

class LeafNode: public HuffmanNode {
	KeyValPair<int, char>* leaf;
public:
	LeafNode(int frequency, char value) {
		leaf = new KeyValPair<int, char>(frequency, value);
	}

	~LeafNode() {
		delete leaf;
	}

	int getWeight() const {
		return leaf->getKey();
	}
	bool isLeaf() const {
		return true;
	}
	char getValue() const {
		return leaf->getElem();
	}
};

class InternalNode: public HuffmanNode {
	HuffmanNode* left;
	HuffmanNode* right;
	int weight;
public:
	InternalNode(HuffmanNode* left, HuffmanNode* right) {
		if (left != nullptr && right != nullptr) {
			weight = left->getWeight() + right->getWeight();
			this->left = left;
			this->right = right;
		}
	}

	int getWeight() const {
		return weight;
	}
	HuffmanNode* getLeft() const {
		return left;
	}
	void setLeft(HuffmanNode* toSet) {
		if (toSet != nullptr) {
			left = toSet;
		}
	}
	HuffmanNode* getRight() const {
		return right;
	}
	void setRight(HuffmanNode* toSet) {
		if (toSet != nullptr) {
			right = toSet;
		}
	}

	char getValue() const {
		return -1;
	}
};

#endif /* HUFFMANNODE_H_ */
