#include <iostream>

using namespace std;

Stack::Stack(int m) {
	head = 0;
	max = m;
	stack = new int[max];
}

Stack::Stack(int existing[],int esize, int m){
	head = esize;
	max = m;
	stack = new int[max];
	for(int i = 0; i<head; i++){
		stack[i] = existing[i];
	}
}

Stack::~Stack() { delete[] stack; }

void Stack::push(int val){
	if(head == max){
		cout << "Stack overflow." << endl;
	}
	else{
		stack[head++] = val;
	}
}

int Stack::pop(){
	if(head == 0){
		cout << "Stack underflow." << endl;
		return -1;
	}
	return head--;
}
