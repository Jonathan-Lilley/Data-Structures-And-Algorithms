#include <iostream>
#include <map>
#include "huffman.h"

using namespace std;

int main() {
	cout << endl;
	int values[SPAN];
	charCounts(values, "rules.txt");
	int count = getCharCount(values);
	Node* nodes[count];
	valueReader(nodes,values);
	Node* root = buildTree(nodes,count);
	printTree(root);
	map<char,int> freqMap = createMap(root);
	
	deleteTree(root);
	cout << endl;
}