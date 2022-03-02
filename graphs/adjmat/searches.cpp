#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"
#include "graph.h"
#include "searches.h"

using namespace std;

int breadthFirst(Graph* graph, string target) {
	Queue* queue = newQueue();
	bool visited[graph->count];
	int node;
	for(int i = 0; i < graph->count; i++) {
		visited[i] = false;
	}
	for(int i = 0; i < graph->count; i++) {
		node = i;
		enqueue(queue,node);
		while(!qEmpty(queue)) {
			node = dequeue(queue);
			if(visited[node]) {
				continue;
			}
			if(graph->nodes[node]->name == target) {
				deleteQueue(queue);
				return node;
			}
			for(int j = 0; j < graph->count; j++) {
				if(getIdx(graph->matrix, node, j, graph->count) > 0) {
					if(visited[j]) {
						continue;
					}
					enqueue(queue,j);
				}
			}
		}
	}
	deleteQueue(queue);
	return -1;
}

int depthFirst(Graph* graph, string target) {
	Stack* stack = newStack();
	bool visited[graph->count];
	int node;
	for(int i = 0; i < graph->count; i++) {
		visited[i] = false;
	}
	for(int i = 0; i < graph->count; i++) {
		node = i;
		push(stack,node);
		while(!sEmpty(stack)) {
			node = pop(stack);
			printStack(stack);
			if(visited[node]) {
				continue;
			}
			visited[node] = true;
			if(graph->nodes[node]->name == target) {
				deleteStack(stack);
				return node;
			}
			for(int j = 0; j < graph->count; j++) {
				if(getIdx(graph->matrix, node, j, graph->count) > 0) {
					if(visited[j]) {
						continue;
					}
					push(stack,j);
				}
			}
		}
	}
	deleteStack(stack);
	return -1;
}