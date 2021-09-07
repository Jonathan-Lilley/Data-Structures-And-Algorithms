#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class Stack {
	
private:

	int* stack;
	int head;
	int max;
	
public:

	Stack(int m) {
		head = 0;
		max = m;
		stack = new int[max];
	}
	
	Stack(int existing[],int esize, int m){
		head = esize;
		max = m;
		stack = new int[max];
		for(int i = 0; i<head; i++){
			stack[i] = existing[i];
		}
	}
	
	~Stack() { delete[] stack; }
	
	void push(int val){
		if(head == max){
			cout << "Stack overflow." << endl;
		}
		else{
			stack[head++] = val;
		}
	}
	
	int pop(){
		if(head == 0){
			cout << "Stack underflow." << endl;
			return -1;
		}
		return head--;
	}
	
};


#endif