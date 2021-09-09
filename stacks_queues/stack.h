#ifndef STACK_H
#define STACK_H

class Stack {

private:
	int* stack;
	int head;
	int max;

public:
	Stack(int m);
	Stack(int existing[],int esize, int m);
	~Stack();
	void push(int val);
	int pop();

};


#endif