#include <iostream>
#include "tests.cpp"

using namespace std;

void bubbleSort(int arr[], int len) {
	int temp;
	for(int i = 0; i < len; i++) {
		for(int j = i; j > 0; j--) {
			if(arr[j] < arr[j-1]) {
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

int main(int argc, char** argv) {
	int max = 1000;
	int array[max];
	for(int i = 0; i < max; i++) {
		array[i] = rand() % 500;
	}
	testFunc(max, array, &bubbleSort);
}