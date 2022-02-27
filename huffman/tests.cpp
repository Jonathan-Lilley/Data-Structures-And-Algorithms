#include <iostream>
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
	deleteTree(root);
	cout << endl << endl;
}