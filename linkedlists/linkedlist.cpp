#include <iostream>
#include <vector>
#include <algorithm>
#include "linkedlist.h"

using namespace std;

void addChild(Node* root, int val){
	if(root->child){
		addChild(root->child, val);
	}
	else{
		root->child = newNode(val);
	}
}

void printAll(Node* root){
	cout << root->val << " ";
	if(root->child){
		printAll(root->child);
	}
}

int getLast(Node* root){
	if(!root->child){
		return root->val;
	}
	return getLast(root->child);
}

int getByIdx(Node* root, int idx){
	if(idx < 0){
		return root->val;
	}
	return getByIdx(root->child, --idx);
}

void delAll(Node* root, vector<Node*> ptrs)	{
	vector<Node*>::iterator found = find(ptrs.begin(),ptrs.end(),root);
	if(found != ptrs.end()){
		return;
	}
	ptrs.push_back(root);
	if(root->child){
		delAll(root->child,ptrs);
	}
	delete root;
}

void delByIdx(Node* root, int idx){
	if(idx == 1){
		Node* temp = root->child->child;
		delete root->child;
		root->child = temp;
	}
	else{
		delByIdx(root->child,idx-1);
	}
}

void insertByIdx(Node* root, int idx, int val){
	if(idx == 1){
		Node* temp = newNode(val);
		temp->child = root->child;
		root->child = temp;
	}
	else{
		insertByIdx(root->child, --idx, val);
	}
}

int findLengthR(Node* root){
	if(root->child){
		return 1 + findLengthR(root->child);
	}
	return 0;
}

int findLengthI(Node* root){
	int ttl = 0;
	while(root->child){
		ttl++;
		root = root->child;
	}
	return ttl;
}

Node* findValNode(Node* root, int val){
	if(root->val == val){
		return root;
	}
	if(root->child){
		return findValNode(root->child,val);
	}
	return nullptr;
}

int idxFromEnd(Node* root, int idx, int end){
	int cur = -1;
	while(root->child){
		if(cur == end - idx){
			return root->val;
		}
		cur++;
		root = root->child;
	}
	return -1;
}

int middle(Node* root){
	Node* droot = root;
	while(droot->child->child){
		root = root->child;
		droot = droot->child->child;
	}
	return root->val;
}

Node* getLastNode(Node* root){
	while(root->child){
		return getLastNode(root->child);
	}
	return root;
}

void hasLoop(Node* root, vector<Node*> ptrs){
	if(!root->child){
		cout << "No loops";
		return;
	}
	vector<Node*>::iterator found = find(ptrs.begin(),ptrs.end(),root);
	if(found != ptrs.end()){
		cout << "Loop found";
		return;
	}
	ptrs.push_back(root);
	hasLoop(root->child,ptrs);
}