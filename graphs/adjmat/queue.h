#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

typedef struct Queue {
	int front;
	int back;
	int size;
	int* nodes;
} Queue;

Queue* newQueue();

void enqueue(Queue*,int);

int dequeue(Queue*);

void expandQueue(Queue*);

bool qEmpty(Queue*);

void deleteQueue(Queue*);

void printQueue(Queue*);

#endif