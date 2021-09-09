#include <iostream>
#include <cassert>
#include "rbtree.h"

using namespace std;

int main(){
	cout << "Initialize array for insertion: 4 12 3 1 10 15 20 13 11 19 18" << endl;
	int arr1[] = { 9, 4, 12, 3, 1, 10, 15, 20, 13, 11, 19, 18 };
	cout << endl;

	cout << "Root: 0" << endl;
	Node* root = newNode(0);
	cout << endl;

	cout << "Read in the array" << endl;
	for(auto item: arr1){
		cout << "Inserting " << item << endl;
		addChild(root,item);
		assert(root);
		cout << "By level" << endl;
		printByLevel(root,1);
		cout << endl;
	}
	cout << endl;

	cout << "Final root: " << root->val << endl << endl;

	cout << "Auto balanced? Lets print low to high" << endl;
	printLowtoHigh(root);
	cout << endl << endl;

	cout << "Print by level" << endl;
	printByLevel(root,1);
	cout << endl << endl;

	getDepth(root);
	cout << endl;

	cout << "Delete tree" << endl;
	delTree(root);
	cout << endl;

	cout << "Done!" << endl;
	cout << endl;

	return 0;
}