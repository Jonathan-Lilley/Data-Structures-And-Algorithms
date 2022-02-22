#ifndef HEAP_H
#define HEAP_H

typedef struct Node {
	int val;
	Node* left;
	Node* right;
} Node;

Node* newNode(int);

void addNode(Node*, int);

void maxHeapify(Node*);