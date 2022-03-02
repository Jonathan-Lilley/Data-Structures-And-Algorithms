#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <map>
#include "huffman.h"

using namespace std;

Node* newNode(int val) {
	Node* n = new Node;
	n->ival = val;
	n->chval = '\0';
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

nQueue* newQueue(int size) {
	nQueue* q = new nQueue;
	q->size = size+1;
	q->nodes = new Node*[q->size];
	for(int i = 0; i < q->size; i++) {
		q->nodes[i] = nullptr;
	}
	q->front = 0;
	q->back = 0;
	return q;
}

void setChar(Node* n, char ch) {
	n->chval = ch;
}

void enqueue(nQueue* queue, Node* n) {
	if(queue->front-1 == queue->back || (queue->back == queue->size-1 && queue->front == 0)) {
		cout << "Queue overflow." << endl;
	}
	queue->nodes[queue->back] = n;
	queue->back++;
	if(queue->back == queue->size) {
		queue->back = 0;
	}
}

Node* dequeue(nQueue* queue){
	if(queue->front == queue->back) {
		cout << "Queue underflow." << endl;
		return nullptr;
	}
	Node* retval = queue->nodes[queue->front];
	queue->front++;
	if(queue->front == queue->size) {
		queue->front = 0;
	}
	return retval;
}

bool qEmpty(nQueue* queue) {
	if(queue->front == queue->back) {
		return true;
	}
	return false;
}

void merge(Node* nodes[], int l, int m, int r) {
	Node* L[m-l];
	Node* R[r-m];
	int i = 0;
	int j = 0;
	int k = l;
	int imax = m-l;
	int jmax = r-m;
	
	copyNodeArr(nodes,L,l,m);
	copyNodeArr(nodes,R,m,r);
	
	while(i < imax && j < jmax) {
		if(L[i] && R[j]) {
			if(L[i]->ival < R[j]->ival) {
				nodes[k] = L[i];
				i++;
			}
			else {
				nodes[k] = R[j];
				j++;
			}
		}
		else if(L[i]) {
			nodes[k] = L[i];
			i++;
		}
		else {
			nodes[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i < imax) {
		nodes[k] = L[i];
		i++;
		k++;
	}
	
	while(j < jmax) {
		nodes[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(Node* nodes[], int l, int r) {
	if(r-l <= 1) {
		return;
	}
	int m = (r-l)/2+l;
	mergeSort(nodes,l,m);
	mergeSort(nodes,m,r);
	merge(nodes,l,m,r);
}

int getDepth(Node* root) {
	if(!root->left) {
		return 0;
	}
	return 1 + getDepth(root->left);
}

int getLeafNum(Node* root) {
	return pow(2,getDepth(root))+pow(2,getDepth(root)+1);
}

void printTree(Node* root) {
	nQueue* queue = newQueue(getLeafNum(root));
	enqueue(queue,root);
	while(!qEmpty(queue)) {
		root = dequeue(queue);
		cout << root->chval << ":" << root->ival << ", ";
		if(root->left) {
			enqueue(queue,root->left);
		}
		if(root->right) {
			enqueue(queue,root->right);
		}
	}
	delete queue;
	cout << endl;
}

void copyNodeArr(Node* nodes[], Node* copyarr[], int l, int r) {
	for(int i = l; i < r; i++) {
		copyarr[i-l] = nodes[i];
	}
}

Node* buildTree(Node* nodes[], int top) {
	Node* t;
	mergeSort(nodes,0,top);
	while(nodes[1]) {
		t = newNode(nodes[0]->ival+nodes[1]->ival);
		t->left = nodes[0];
		t->right = nodes[1];
		nodes[0] = t;
		nodes[1] = nullptr;
		mergeSort(nodes,0,top);
		top--;
	}
	return nodes[0];
}

void deleteTree(Node* root) {
	if(root->left) {
		deleteTree(root->left);
	}
	if(root->right) {
		deleteTree(root->right);
	}
	delete root;
}

void charCounts(int values[], string filename) {
	for(int i = 0; i < SPAN; i++) {
		values[i] = 0;
	}
	ifstream inFile;
	inFile.open(filename);
	char c;
	while(inFile.get(c)) {
		if(c-MIN > 0) {
			values[c-MIN]++;
		}
	}
	inFile.close();
}

int getCharCount(int values[]){
	int count = 0;
	for(int i = 0; i < SPAN; i++) {
		if(values[i] > 0) {
			count++;
		}
	}	
	return count;
}

void valueReader(Node* nodes[], int values[]) {
	int top = 0;
	for(int i = 0; i < SPAN; i++) {
		if(values[i] > 0) {
			nodes[top] = newNode(values[i]);
			setChar(nodes[top],i+MIN);
			top++;
		}
	}
}

map<char,int> createMap(Node* root) {
	map<char,int> freqMap;
	nQueue* queue = newQueue(getLeafNum(root));
	enqueue(queue,root);
	while(!qEmpty(queue)) {
		root = dequeue(queue);
		if(root->left) {
			enqueue(queue,root->left);
		}
		if(root->right) {
			enqueue(queue,root->right);
		}
		else {
			freqMap.insert(pair<char,int>(root->chval,root->ival));
		}
	}
	delete queue;
	return freqMap;
}

int fileLen(string filename) {
	ifstream inFile;
	inFile.open(filename);
	int count = 0;
	char c;
	while(inFile.get(c)) {
		count++;
	}
	return count;
}

int