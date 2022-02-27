#ifndef HUFFMAN_H
#define HUFFMAN_H
#define MIN 32
#define SPAN 95
#include <string.h>

typedef struct Node {
	char chval;
	int ival;
	Node* left;
	Node* right;
} Node;

typedef struct nQueue {
	int size;
	Node** nodes;
	int front;
	int back;
} nQueue;

Node* newNode(int);

void setChar(Node*,char);

nQueue* newQueue(int);

Node* dequeue(nQueue*);

void enqueue(nQueue*,Node*);

bool qEmpty(nQueue*);

void merge(Node*[],int,int,int);

void mergeSort(Node*[],int,int);

int countNodes(Node*,int);

int getDeptb(Node*);

int getLeafNum(Node*);

void printTree(Node*);

void copyNodeArr(Node*[],Node*[],int,int);

Node* buildTree(Node*[],int);

void deleteTree(Node*);

void charCounts(int[],std::string);

int getCharCount(int[]);

void valueReader(Node*[],int[]);

#endif