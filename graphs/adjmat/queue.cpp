#include <iostream>
#include "queue.h"

using namespace std;

Queue* newQueue() {
	Queue* q = new Queue;
	q->size = 2;
	q->front = 0;
	q->back = 0;
	q->nodes = new int[2];
	return q;
}

void enqueue(Queue* queue, int node) {
	queue->nodes[queue->back] = node;
	queue->back++;
	if(queue->back == queue->size) {	
		queue->back = 0;
	}
	if(queue->front == queue->back+1 || (queue->front == 0 && queue->back == queue->size-1)) {
		expandQueue(queue);
	}
}

int dequeue(Queue* queue) {
	if(queue->front == queue->back) {
		cout << "Queue underflow." << endl;
		return -1;
	}
	int n = queue->nodes[queue->front];
	queue->front++;
	if(queue->front == queue->size) {
		queue->front = 0;
	}
	return n;
}

void expandQueue(Queue* queue) {
	int* newNodes = new int[queue->size*2];
	int j = queue->front;
	int i = 0;
	while(j < queue->size) {
		newNodes[i] = queue->nodes[j];
		i++;
		j++;
	}
	if(queue->back < queue->front) {
		j = 0;
		while(j < queue->front) {
			newNodes[i] = queue->nodes[j];
			i++;
			j++;
		}
	}
	delete[] queue->nodes;
	queue->front = 0;
	queue->back = queue->size-1;
	queue->size *= 2;
	queue->nodes = newNodes;
}

bool qEmpty(Queue* queue) {
	if(queue->front == queue->back) {
		return true;
	}
	return false;
}

void deleteQueue(Queue* queue) {
	delete[] queue->nodes;
	delete queue;
}

void printQueue(Queue* queue) {
	cout << "size: " << queue->size << endl;
	cout << "front/back: " << queue->front << " " << queue->back << endl;
	int start = queue->front;
	int end = queue->back;
	if(start == end) {
		cout << "Queue empty" << endl;
		return;
	}
	if(end < start) {
		for(int i = start; i < queue->size; i++) {
			cout << queue->nodes[i] << " ";
		}
		for(int i = 0; i < end; i++) {
			cout << queue->nodes[i] << " ";
		}
	}
	else {
		for(int i = start; i < end; i++) {
			cout << queue->nodes[i] << " ";
		}
	}
	cout << endl;
}