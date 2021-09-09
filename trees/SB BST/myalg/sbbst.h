#ifndef SB_BST_H
#define SB_BST_H

typedef struct Node {
	int val;
	Node* left;
	Node* right;
} Node;

Node* newNode(int);

Node* cpNode(Node*);

void addChild(Node*, int);

void delTree(Node*);

int treeDepth(Node*);

void insertNode(Node*);

bool balanced(Node*);

void balance(Node*);

Node* findChild(Node*, int);

void printLowtoHigh(Node*);

void printHightoLow(Node*);

void printByLevel(Node*, int);

void getDepth(Node*);


#endif