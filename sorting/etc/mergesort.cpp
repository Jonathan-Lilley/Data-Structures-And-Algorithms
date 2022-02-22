#include <iostream>
#include "utility.cpp"

using namespace std;

void merge(int arr[], int l, int m, int r) {
	int left[m-l];
	int right[r-m];
	int i = 0;
	int j = 0;
	int k = l;
	int imax = m-l;
	int jmax = r-m;
	
	copyArr(arr, left, l, m);
	copyArr(arr, right, m, r);
	
	while(i < imax && j < jmax) {
		if(left[i] < right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while(i < imax) {
		arr[k] = left[i];
		k++;
		i++;
	}
	while(j < jmax) {
		arr[k] = right[j];
		k++;
		j++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if((r-l) == 0 || (r-l) == 1) {
		return;
	}
	
	int m = ((r-l)/2)+l;
	mergeSort(arr,l,m); 
	mergeSort(arr,m,r);
	merge(arr,l,m,r);	
}


void sort(int arr[], int max) {
	mergeSort(arr,0,max);
}


int main() {
	long max = 1000000;
	int array[max];
	for(int i = 0; i < max; i++) {
		array[i] = rand() % 500;
	}
	
	testFunc(max, array, 100, &sort);
}