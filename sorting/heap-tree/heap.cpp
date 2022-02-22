#include <iostream>
#include "heap.h"


Node* newNode(int v) {
	Node* n = new Node;
	n->val = v;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

void addNode(Node* root, int v) {
	return;
}

void maxHeapify(Node* root) {
	Node* largest = root;
	if(root->left && root->left->val > root->val) {
		largest = root->left;
	}
	else if(root->right && root->right->val > root->val) {
		largest = root->right;
	}
	if(largest != root) {
		int t = root->val;
		root->val = largest->val;
		largest->val = t;
		maxHeapify(largest);
	}
}