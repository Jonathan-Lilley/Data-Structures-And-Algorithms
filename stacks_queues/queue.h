#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Queue {
	
private:

	int* queue;
	int head;
	int tail;
	int max;
	
public:

	Queue(int m) {
		head = 0;
		tail = 0;
		max = m+1;
		queue = new int[max];
	}
	
	Queue(int existing[], int esize, int m){
		if(esize > m - 1){
			cout << "Input larger than max." << endl;
			return;
		}
		head = esize;
		tail = 0;
		max = m+1;
		queue = new int[max];
		for(int i = 0; i<head; i++){
			queue[i] = existing[i];
		}
	}
	
	~Queue() { delete[] queue; }
	
	void enqueue(int val){
		if(head == tail - 1 || (head == max - 1 && tail == 0)){
			cout << "Queue overflow." << endl;
		}
		else{
			queue[tail--] = val;
			if(tail < 0){
				tail = max - 1;
			}
		}
	}
	
	int dequeue(){
		if(head == tail){
			cout << "Queue underflow." << endl;
			return -1;
		}
		int val = queue[head--];
		if(head < 0){
			head = max-1;
		}
		return val;
	}
	
	void headtail(){
		cout << "head is: " << head << endl << "tail is: " << tail << endl;
	}
	
};


#endif