#include <iostream>
#include "bst.h"

using namespace std;


Node* newNode(int val){
	Node* node = new Node;
	node->val = val;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

// left < parent <= right
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

void printByLevel(Node* root);

