#include <iostream>
#include "utility.h"

using namespace std;

void printArr(int arr[], int len, int offset) {
	if(offset >= len) {
		return;
	}
	for(int i = offset; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool checkSorted(int arr[], int len, int offset, bool maxmin) {
	for(int i = offset; i < len-1; i++) {
		if((maxmin && arr[i] > arr[i+1]) || (!maxmin && arr[i] < arr[i+1])) {
			return false;
		}
	}
	return true;
}