#include <iostream>
#include <string>
#include "queue.h"
#include "graph.h"

using namespace std;

int getIdx(int* matrix, int row, int col, int rowlen) {
	return *(matrix+(row*rowlen)+col);
}

Node* newNode(string name) {
	Node* n = new Node;
	n->name = name;
	n->seen = false;
	return n;
}

Graph* newGraph(int count, string nodenames[], int connections[]) {
	Graph* g = new Graph;
	g->count = count;
	g->nodes = new Node*[count];
	g->matrix = new int[count*count];
	for(int i = 0; i < g->count; i++) {
		g->nodes[i] = newNode(nodenames[i]);
	}
	for(int i = 0; i < g->count*g->count; i++) {
		g->matrix[i] = connections[i];
	}
	return g;
}

void printAllNodes(Graph* graph) {
	for(int i = 0; i < graph->count; i++) {
		cout << i << ":" << graph->nodes[i]->name << ", ";
	}
	cout << endl;
}

void printNeighborNodes(Graph* graph) {
	for(int i = 0; i < graph->count; i++) {
		cout << "Node " << i << ": " << graph->nodes[i]->name;
		cout << "; -->     ";
		for(int j = 0; j < graph->count; j++) {
			if(getIdx(graph->matrix, i, j, graph->count) > 0) {
				cout << graph->nodes[j]->name << ", ";
			}
		}
		cout << endl;
	}
}

Node* getNode(Graph* graph, int idx) {
	return graph->nodes[idx];
}

void deleteGraph(Graph* graph) {
	for(int i = 0; i < graph->count; i++) {
		delete graph->nodes[i];
	}
	delete[] graph->nodes;
	delete[] graph->matrix;
	delete graph;
}