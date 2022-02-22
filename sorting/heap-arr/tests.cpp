#include <iostream>
#include <time.h>
#include "heap.h"
#include "utility.h"

using namespace std;

int main(int argc, char** argv) {
	int max = 11;
	int heap[max];
	heap[0] = 0;
	for(int i = 1; i < max; i++) {
		heap[i] = rand() % 500;
	}
	time_t start;
	time_t end;
	
	cout << "Before heapify:" << endl;
	printArr(heap,max,1);
	
	cout << "Min heapify:" << endl;
	time(&start);
	heapifyArr(heap, max, false);
	time(&end);
	printArr(heap, max, 1);
	cout << "elapsed: " << difftime(end,start) << " seconds" << endl;	
	if(validateHeap(heap,max,1,false)) {
		cout << "Min heap valid" << endl;
	}
	else {
		cout << "Min heap invalid" << endl;
	}
	
	cout << "Min Heapsort:" << endl;
	time(&start);
	heapSort(heap, max, false);
	time(&end);
	printArr(heap, max, 1);
	if(checkSorted(heap,max,1,false)) {
		cout << "Sorted" << endl;
	}
	else {
		cout << "Unsorted" << endl;
	}	
	
	cout << "Max heapify:" << endl;
	time(&start);
	heapifyArr(heap, max, true);
	time(&end);
	printArr(heap, max, 1);
	cout << "elapsed: " << difftime(end,start) << " seconds" << endl;
	if(validateHeap(heap,max,1,true)) {
		cout << "Max heap valid" << endl;
	}
	else {
		cout << "Max heap invalid" << endl;
	}
	
	cout << "Max Heapsort:" << endl;
	time(&start);
	heapSort(heap, max, true);
	time(&end);
	printArr(heap, max, 1);
	if(checkSorted(heap,max,1,true)) {
		cout << "Sorted" << endl;
	}
	else {
		cout << "Unsorted" << endl;
	}
	
}