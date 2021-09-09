#ifndef RBTREE_H
#define RBTREE_H

enum color_t { BLACK, RED };

typedef struct Node {
	int val;
	color_t color; // true = black, false = red
	Node* left;
	Node* right;
} Node;

Node* newNode(int);

int numBlack(Node*);

void addChild(Node*, int);

void delTree(Node*);

void insertNode(Node*);

bool balanced(Node*);

void balance(Node*);

Node* findChild(Node*, int);

void printLowtoHigh(Node*);

void printHightoLow(Node*);

void printByLevel(Node*, int);



#endif