#ifndef GRAPH_H
#define GRAPH_H
#include <string>

typedef struct Node {
	std::string name;
	bool seen;
} Node;

typedef struct Graph {
	int count;
	Node** nodes;
	int* matrix;
} Graph;

int getIdx(int*,int,int,int);

Node* newNode(std::string);

Graph* newGraph(int,std::string[],int[]);

void printAllNodes(Graph*);

void printNeighborNodes(Graph*);

Node* getNode(Graph*,int);

void deleteGraph(Graph*);

#endif