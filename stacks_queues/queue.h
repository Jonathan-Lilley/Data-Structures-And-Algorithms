#ifndef QUEUE_H
#define QUEUE_H

class Queue {

private:
	int* queue;
	int head;
	int tail;
	int max;

public:
	Queue(int m);
	Queue(int existing[], int esize, int m);
	~Queue();
	void enqueue(int val);
	int dequeue();
	void headtail();
};


#endif