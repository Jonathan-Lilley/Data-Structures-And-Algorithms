#include <iostream>
#include "heap.h"

using namespace std;

int parent(int i) {
	return i/2;
}

int left(int i) {
	return 2*i;
}

int right(int i) {
	return (2*i)+1;
}

bool validateHeap(int heap[], int heapsize, int i, bool maxmin) {
	int l = left(i);
	int r = right(i);
	bool valid = true;
	if(l < heapsize) {
		if((maxmin && heap[l] > heap[i]) || (!maxmin && heap[l] < heap[i])) {
			return false;
		}
		valid = validateHeap(heap, heapsize, l, maxmin);
	}
	if(r < heapsize) {
		if((maxmin && heap[r] > heap[i]) || (!maxmin && heap[r] < heap[i])) {
			return false;
		}
		valid = validateHeap(heap, heapsize, r, maxmin);
	}
	return valid;	
}

void heapify(int heap[], int heapsize, int i, bool maxmin) {
	int l = left(i);
	int r = right(i);
	int exchange = i;
	if(l < heapsize && ((maxmin && heap[l] > heap[i]) || (!maxmin && heap[l] < heap[i]))) {
		exchange = l;
	}
	if(r < heapsize && ((maxmin && heap[r] > heap[exchange]) || (!maxmin && heap[r] < heap[exchange]))) {
		exchange = r;
	}
	if(exchange != i) {
		int t = heap[i];
		heap[i] = heap[exchange];
		heap[exchange] = t;
		heapify(heap, heapsize, exchange, maxmin);
	}
	
}

void heapifyArr(int heap[], int heapsize, bool maxmin) {
	for(int i = heapsize/2; i > 0; i--) {
		heapify(heap, heapsize, i, maxmin);
	}
}

void heapSort(int heap[], int heapsize, bool maxmin) {
	while(heapsize > 2) {
		int t = heap[1];
		heap[1] = heap[heapsize-1];
		heap[heapsize-1] = t;
		heapsize--;
		heapify(heap, heapsize, 1, maxmin);
	}
}