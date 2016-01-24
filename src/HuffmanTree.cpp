/*
 * HuffmanTree.cpp
 *
 *  Created on: Dec 27, 2015
 *      Author: erolh
 */

#include "HuffmanTree.h"

#include <queue>
#include <vector>

#include "BitString.h"
#include "HuffmanNodes.h"

bool compareNodes(HuffmanNode* first, HuffmanNode* second) {
	return first->getWeight() > second->getWeight();
}

HuffmanNode* popHeap(vector<HuffmanNode*> &heap) {
	pop_heap(heap.begin(), heap.end(), compareNodes);
	HuffmanNode* temp = heap.back();
	heap.pop_back();
	return temp;
}

void pushHeap(vector<HuffmanNode*> &heap, HuffmanNode* toPush) {
	heap.push_back(toPush);
	push_heap(heap.begin(), heap.end(), compareNodes);
}

HuffmanNode* HuffmanTree::buildHuffmanTree(const FrequencyTable& freqTable) {
	auto nodes = freqTable.getNodes();
	make_heap(nodes.begin(), nodes.end(), compareNodes);

	if (nodes.size() <= 1) {
		while (nodes.size() < 2)
			pushHeap(nodes, new LeafNode(9, nodes.size()));
	}

	HuffmanNode *temp1, *temp2, *temp3;
	while (nodes.size() > 1) {
		temp1 = popHeap(nodes);
		temp2 = popHeap(nodes);
		temp3 = new InternalNode(temp1, temp2);

		pushHeap(nodes, temp3);
	}
	return temp3; // root of our Huffman tree
}

HuffmanTree::HuffmanTree(const FrequencyTable& freqTable) {
	root = buildHuffmanTree(freqTable);
	codingTable = CodingTable(*root);
}

ostream& operator<<(ostream& os, const HuffmanTree& tree) {
	os << tree.codingTable;
	return os;
}

string HuffmanTree::decode(const BitString& toDecode) const {
	string toReturn;
	vector<bool>::const_iterator toIter = toDecode.getBegin();
	vector<bool>::const_iterator end = toDecode.getEnd();
	HuffmanNode* treeIter = root;
	while (toIter != end) {
		if (!treeIter->isLeaf()) {
			if (*toIter)
				treeIter = treeIter->getRight();
			else
				treeIter = treeIter->getLeft();
			toIter++;
		}
		if (treeIter->isLeaf()) {
			toReturn += treeIter->getValue();
			treeIter = root;
		}
	}

	return toReturn;
}

string HuffmanTree::encodeToByte(const string& toEncode) const {
	return codingTable.encode(toEncode).toString();
}

BitString HuffmanTree::encode(const string& toEncode) const {
	BitString toReturn = codingTable.encode(toEncode);
	return toReturn;
}
