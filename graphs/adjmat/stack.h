#ifndef STACK_H
#define STACK_H

typedef struct Stack {
	int max;
	int top;
	int* nodes;
} Stack;

Stack* newStack();

void push(Stack*,int);

int pop(Stack*);

void expandStack(Stack*);

bool sEmpty(Stack*);

void deleteStack(Stack*);

void printStack(Stack*);

#endif