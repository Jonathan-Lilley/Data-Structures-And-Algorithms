#include <iostream>
#include <time.h>

using namespace std;

void copyArr(int inparr[], int outparr[], int l, int r) {
	int i = 0;
	for(int j = l; j < r; j++) {
		outparr[i++] = inparr[j];
	}
}

bool checkSorted(int arr[], int len) {
	for(int i = 1; i < len; i++) {
		if(arr[i] < arr[i-1]) {
			cout << "unsorted items: ";
			cout << arr[i-1] << " " << arr[i] << endl;
			return false;
		}
	}
	return true;
}

void printRange(int arr[], int len, int l, int r) {
	if(l < 0) {
		l = 0;
	}
	if(r > len) {
		r = len;
	}
	cout << "printing range " << l << " to " << r << endl;
	for(int i = l; i < r; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void testFunc(int max, int arr[], void (*func)(int[],int)) {
	cout << "sorting " << max << " items" << endl;
	time_t start;
	time_t end;
	time(&start);
	func(arr, max);
	time(&end);
	if(checkSorted(arr,max)) {
		cout << "Sorted" << endl;
	}
	else {
		cout << "Unsorted" << endl;
	}
	printRange(arr,max,0,20);
	cout << "elapsed: " << difftime(end,start) << " seconds" << endl;
}