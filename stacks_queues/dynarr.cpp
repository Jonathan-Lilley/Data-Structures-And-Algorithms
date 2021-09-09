#include <iostream>
#include "dynarr.h"

using namespace std;

DynArr::DynArr(void) { head = 0; max = 2; arr = new int[max]; }

DynArr::DynArr(int existing[],int esize){
		head = esize;
		max = head + 1; // max should be at least 1 more than the head
		arr = new int[max];
		for(int i = 0; i<head; i++){
			arr[i] = existing[i];
		}
	}

DynArr::~DynArr() { delete[] arr; }

void DynArr::expand(){
	max *= 2;
	int* newarr = new int[max];
	for(int i = 0; i<head; i++){
		newarr[i] = arr[i];
	}
	delete[] arr;
	arr = newarr;
}

void DynArr::condense(){
	max /= 2;
	int* newarr = new int[max];
	for(int i = 0; i<head; i++){
		newarr[i] = arr[i];
	}
	delete[] arr;
	arr = newarr;
}

void DynArr::append(int val){
	arr[head++] = val;
	if(head == max){
		expand();
	}
}

void DynArr::remove(){
	if(head == 0){
		return;
	}
	head--;
	if(head == max/2){
		condense();
	}
}

int DynArr::operator[](int idx){
	if(idx > head || idx < 0){
		return 0;
	}
	return arr[idx];
}

void DynArr::printArr(){
	if(head == 0){
		cout << "Array empty." << endl;
	}
	for(int i = 0; i<head; i++){
		cout << arr[i] << endl;
	}
}