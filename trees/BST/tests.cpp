#include <iostream>
#include "bst.h"

using namespace std;

int main(){
	cout << "Initializing array" << endl;
	int arr1[] = { 5, 3, 5, 7, 3, 2, 12, 10, 1 };
	cout << "Array is as follows: ";
	for(auto item: arr1){
		cout << item << " ";
	}
	cout << endl << endl;
	
	cout << "Creating root node; 6" << endl;
	Node* root = newNode(6);
	cout << endl;
	
	cout << "Adding arr1" << endl;
	for(auto item: arr1){
		addChild(root,item);
	}
	cout << endl;
	
	cout << "Finding item 3" << endl;
	cout << findChild(root,3)->val << endl;
	cout << endl;
	
	cout << "Printing low to high; should get\n1 2 3 3 5 5 6 7 10 12" << endl;
	printLowtoHigh(root);
	cout << endl << endl;
	
	cout << "Printing high to low; should get\n12 10 7 6 5 5 3 3 2 1" << endl;
	printHightoLow(root);
	cout << endl << endl;
	
	cout << "Emptying tree" << endl;
	delTree(root);
	cout << endl;
	
	cout << "Done" << endl << endl;
	
	return 0;
}