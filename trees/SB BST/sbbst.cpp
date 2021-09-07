#include <iostream>
#include <algorithm>
#include <cstring>
#include "sbbst.h"

using namespace std;

Node* newNode(int val){
	Node* node = new Node;
	node->val = val;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

Node* cpNode(Node* node){
	Node* copy = new Node;
	copy->val = node->val;
	copy->left = node->left;
	copy->right = node->right;
	return copy;
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
	cout << "Before balance ";
	printLowtoHigh(root);
	cout << endl;
	if(!balanced(root)){
		balance(root);
	}
	cout << "After balance ";
	printLowtoHigh(root);
	cout << endl << endl;
}

int treeDepth(Node* root){
	if(!root){
		return 0;
	}
	return max(treeDepth(root->left)+1, treeDepth(root->right)+1);
}

bool balanced(Node* root){
	if(!root){
		return true;
	}
	return (abs(treeDepth(root->right) - treeDepth(root->left)) < 2 &&
		balanced(root->left) && balanced(root->right));
}

void insertNode(Node* root, Node* ins){
	getDepth(root);
	cout << "Pritning tree" << endl;
	printLowtoHigh(root);
	cout << endl;
	if(ins->val < root->val){
		if(root->left){
			insertNode(root->left,ins);
		}
		else{
			cout << "Inserting " << ins->val << " left of " << root->val << endl;
			root->left = ins;
		}
	}
	else{
		if(root->right){
			insertNode(root->right,ins);
		}
		else{
			cout << "Inserting " << ins->val << " right of " << root->val << endl;
			root->right = ins;
		}
	}
}

void balance(Node* root){
	cout << root->val << " is the root" << endl;
	if(root->left){
		balance(root->left);
	}
	if(root->right){
		balance(root->right);
	}
	while(abs(treeDepth(root->left) - treeDepth(root->right)) > 1){
		cout << "uneven lengths, " << root->val << " is the root" << endl;
		cout << treeDepth(root->left) << " left depth" << endl;
		cout << treeDepth(root->right) << " right depth" << endl;
		while((treeDepth(root->left) - treeDepth(root->right)) > 1){
			cout << "In left" << endl;
			cout << "Current root stuff" << endl;
			cout << root->val << " " << root->right->val << " " << root->left->val << endl;
			Node* temp = cpNode(root);
			delete root;
			root = temp->left;
			cout << root->val << " Is thew new root" << endl;
			cout << "print root stuff" << endl;
			cout << root->val << " " << root->right->val << " " << root->left->val << endl;
			insertNode(root,temp);
			if(temp->val < root->val){
				root->left->left = nullptr;
			}
			else{
				root->right->left = nullptr;
			}
		}
		while((treeDepth(root->right) - treeDepth(root->left)) > 1){
			cout << "In right" << endl;
			cout << "Current root stuff" << endl;
			cout << root->val << " " << root->right->val << " " << root->left->val << endl;
			Node* temp = cpNode(root);
			delete root;
			root = temp->right;
			cout << root->val << " Is thew new root" << endl;
			cout << "print root stuff" << endl;
			cout << root->val << " " << root->right->val << " " << root->left->val << endl;
			insertNode(root,temp);
			if(temp->val < root->val){
				root->left->right = nullptr;
			}
			else{
				root->right->right = nullptr;
			}
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

void printByLevel(Node* root){
	if(root->left){
		printByLevel(root->left);
	}
	if(root->right){
		printByLevel(root->right);
	}
	cout << root->val << " ";
}

void getDepth(Node* root){
	cout << "Depth for node with val " << root->val << ":" << endl;
	cout << "Left depth: " << treeDepth(root->left) << endl;
	cout << "Right depth: " << treeDepth(root->right) << endl;
	cout << endl;
}