#include <iostream>
#include <vector>
#include "llmethods.h"
#include "linkedlist.h"

int main(){
	cout << "Initialize first" << endl;
	Node* root = newNode(0);
	
	cout << "Test print on one node; should get 0" << endl;
	printAll(root);
	cout << endl;
	
	cout << "Add 5" << endl;
	for(int i = 1; i < 6; i++){
		addChild(root,i);
	}
	cout << endl;
	
	cout << "Print out; should get 0-5" << endl;
	printAll(root);
	cout << endl;
	
	cout << "Get last; should get 5" << endl;
	cout << getLast(root) << endl;
	cout << endl;
	
	cout << "get index 2; should get 2" << endl;
	cout << getByIdx(root,2) << endl;
	cout << endl;
	
	cout << "Insert 6 at index 3" << endl;
	insertByIdx(root,3,6);
	cout << endl;
	
	cout << "then print; should get\n0 1 2 6 3 4 5" << endl;
	printAll(root);
	cout << endl << endl;
	
	cout << "delete index 4" << endl;
	delByIdx(root,4);
	cout << endl;
	
	cout << "then print; should get\n0 1 2 6 4 5" << endl;
	printAll(root);
	cout << endl << endl;
	
	cout << "Length recursive; should get 5" << endl;
	cout << findLengthR(root) << endl;
	cout << endl;
	
	cout << "Length iterative; should get 5" << endl;
	cout << findLengthI(root) << endl;
	cout << endl;
	
	cout << "Find node's val of val; should return 2" << endl;
	cout << findValNode(root,2)->val << endl;
	cout << endl;
	
	cout << "Find 2nd from end; should return 4" << endl;
	cout << idxFromEnd(root,2,findLengthI(root)) << endl;
	cout << endl;
	
	cout << "Find middle val; should return 2" << endl;
	cout << middle(root) << endl;
	cout << endl;
	
	cout << "New list!" << endl;
	Node* root2 = newNode(0);
	for(int i = 1; i < 6; i++){
		addChild(root2,i);
	}
	getLastNode(root2)->child = root2->child;
	
	cout << "Has loop? yes" << endl;
	vector<Node*> ptrs2;
	hasLoop(root2,ptrs2);
	cout << endl << endl;
	
	cout << "Has loop? no" << endl;
	vector<Node*> ptrs;
	hasLoop(root,ptrs);
	cout << endl << endl;
	
	ptrs.erase(ptrs.begin(),ptrs.end());
	delAll(root,ptrs);
	cout << "Freed list 1" << endl << endl;
	
	ptrs2.erase(ptrs2.begin(),ptrs2.end());
	delAll(root2,ptrs2);
	cout << "Freed list 2" << endl << endl;
	
	return 0;
}