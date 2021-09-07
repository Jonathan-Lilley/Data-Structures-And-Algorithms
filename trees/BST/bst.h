#ifndef BST_H
#define BST_H

#include <iostream>

typedef struct Node{
	int val;
	Node* left;
	Node* right;
} Node;

Node* newNode(int val);

void delTree(Node* root);

void addChild(Node*, int);

Node* findChild(Node*, int);

void printLowtoHigh(Node*);

void printHightoLow(Node*);

void printByLevel(Node*);

#endif