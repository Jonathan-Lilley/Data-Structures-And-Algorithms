#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include "sbbst.h"

using namespace std;

Node* newNode(int val){
	Node* node = new Node;
	node->val = val;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

void addChild(Node* root, int val){
	if(val < root->val){
		if(root->left){
			addChild(root->left,val);
		}
		else{
			root->left = newNode(val);
		}
	}
	else{
		if(root->right){
			addChild(root->right,val);
		}
		else{
			root->right = newNode(val);
		}
	}
	if(!balanced(root)){
		cout << "Unbalanced. Depths: " << endl;
		getDepth(root);
		cout << endl;
		balance(root);
	}
	assert(root);
}



void insertNode(Node* root, Node* ins){
	if(ins->val < root->val){
		if(root->left){
			insertNode(root->left,ins);
		}
		else{
			root->left = ins;
		}
	}
	else{
		if(root->right){
			insertNode(root->right,ins);
		}
		else{
			root->right = ins;
		}
	}
}



int treeDepth(Node* root){
	int l = 1;
	int r = 1;
	if(root->left){
		l = treeDepth(root->left)+1;
	}
	if(root->right){
		r = treeDepth(root->right)+1;
	}
	return max(l,r);
}



void getDepth(Node* root){
	cout << "Depth for node with val " << root->val << ":" << endl;
	cout << "Left depth: ";
	if(root->left){
		cout << treeDepth(root->left);
		cout << endl;
	}
	else{
		cout << "0" << endl;
	}
	cout << "Right depth: ";
	if(root->right){
		cout << treeDepth(root->right);
		cout << endl;
	}
	else{
		cout << "0" << endl;
	}
	cout << endl;
}



bool balanced(Node* root){
	if(root->right && root->left && abs(treeDepth(root->right) - treeDepth(root->left)) > 1){
		return false;
	}
	if(root->left && (treeDepth(root->left) > 2 || !balanced(root->left))){
		return false;
	}
	if(root->right && (treeDepth(root->right) || !balanced(root->right))){
		return false;
	}
	return true;
}



void balance(Node* root){
	// ASSERTION
	assert(root != nullptr);

	int l = 0; int r = 0;
	if(root->left){
		balance(root->left);
		l = treeDepth(root->left);
	}
	if(root->right){
		balance(root->right);
		r = treeDepth(root->right);
	}

	int counter = 0;
	Node* temp;

	while(abs(l-r) > 1){

		temp = new Node;
		*temp = *root;

		if(l-r > 1){
			// ASSERTION
			assert(temp->left);
			*root = *temp->left;
			delete temp->left;
			temp->left = nullptr;
		}

		else if(r-l > 1){
			// ASSERTION
			assert(temp->right);
			*root = *temp->right;
			delete temp->right;
			temp->right = nullptr;
		}

		// ASSERTION
		assert(!temp->right || !temp->left);
		assert(root);

		insertNode(root,temp);

		l = 0; r = 0;
		if(root->left){
			l = treeDepth(root->left);
		}
		if(root->right){
			r = treeDepth(root->right);
		}
		if(++counter > 5){
			cout << "too many counters" << endl;
			return;
		}
	}
	assert(root);
}



void delTree(Node* root){
	if(root->left){
		delTree(root->left);
	}
	if(root->right){
		delTree(root->right);
	}
	delete root;
}



Node* findChild(Node* root, int val){
	if(root->val == val){
		return root;
	}
	else if(root->left){
		return findChild(root->left,val);
	}
	else if(root->right){
		return findChild(root->right,val);
	}
	return nullptr;
}



void printLowtoHigh(Node* root){
	if(root->left){
		printLowtoHigh(root->left);
	}
	cout << root->val << " ";
	if(root->right){
		printLowtoHigh(root->right);
	}
}



void printHightoLow(Node* root){
	if(root->right){
		printHightoLow(root->right);
	}
	cout << root->val << " ";
	if(root->left){
		printHightoLow(root->left);
	}
}



void printByLevel(Node* root, int level){
	cout << "Node on level " << level << ": " << root->val << endl;
	if(root->left){
		printByLevel(root->left,level+1);
	}
	if(root->right){
		printByLevel(root->right,level+1);
	}
}