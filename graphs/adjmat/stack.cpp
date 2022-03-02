#include <iostream>
#include "stack.h"

using namespace std;

Stack* newStack() {
	Stack* stack = new Stack;
	stack->max = 2;
	stack->top = 0;
	stack->nodes = new int[2];
	return stack;
}

void push(Stack* stack, int node) {
	stack->top = node;
	stack->top++;
	if(stack->top == stack->max) {
		expandStack(stack);
	}
}

int pop(Stack* stack) {
	int node = stack->top;
	stack->top--;
	return node;
}

void expandStack(Stack* stack) {
	int* newNodes = new int[stack->max*2];
	for(int i = 0; i < stack->max; i++) {
		newNodes[i] = stack->nodes[i];
	}
	delete[] stack->nodes;
	stack->nodes = newNodes;
	stack->max *= 2;
}

bool sEmpty(Stack* stack) {
	if(stack->top == 0) {
		return true;
	}
	return false;
}

void deleteStack(Stack* stack) {
	delete[] stack->nodes;
	delete stack;
}

void printStack(Stack* stack) {
	cout << "currentStack: ";
	for(int i = 0; i < stack->top; i++) {
		cout << i << " ";
	}
	cout << endl;
}