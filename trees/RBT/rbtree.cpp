#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include "sbbst.h"

using namespace std;

Node* newNode(int val){
	Node* node = new Node;
	node->color = RED;
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



int numBlack(Node* root){
	int black = 0;
	if(root->rb){
		black++;
	}
	if(root->left){
		black += numBlack(root->left);
	}
	if(root->right){
		black += numBlack(root->right);
	}
	return black;
}


// ?
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



bool balanced(Node* root){
	int l = 0;
	int r = 0;
	if(root->left){
		if(!balanced(root->left)){
			return false;
		}
		l = numBlack(root->left);
	}
	if(root->right){
		if(!balanced(root->right)){
			return false;
		}
		l = numBlack(root->right);
	}
	if(abs(l-r) > 0){
		return false;
	}
	return true;
}



void balance(Node* root){
	return;
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