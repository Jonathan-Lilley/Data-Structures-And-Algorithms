#include <iostream>
#include "utility.cpp"

using namespace std;

void insertSort(int arr[], int len) {
	int key;
	int j;
	for(int i = 1; i < len; i++) {
		key = arr[i];
		//cout << "sorting: " << key << endl;
		j = i - 1;
		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(int argc, char** argv) {
	int max = 20;
	int array[max];
	for(int i = 0; i < max; i++) {
		array[i] = rand() % 500;
	}
	testFunc(max, array, &insertSort);
	
}