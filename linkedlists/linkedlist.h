#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
	int val;
	Node* child;
} Node;

Node* newNode(int val){
	Node* node = new Node;
	node->val = val;
	node->child = nullptr;
	return node;
}

#endif