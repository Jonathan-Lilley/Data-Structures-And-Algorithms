#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

using namespace std;

class DynArr {
	
private:

	int* arr;
	int head;
	int max;
	
public:

	DynArr() { head = 0; max = 2; arr = new int[max]; }
	
	DynArr(int existing[],int esize){
		head = esize;
		max = head + 1; // max should be at least 1 more than the head
		arr = new int[max];
		for(int i = 0; i<head; i++){
			arr[i] = existing[i];
		}
	}
	
	~DynArr() { delete[] arr; }
	
	void expand(){
		max *= 2;
		int* newarr = new int[max];
		for(int i = 0; i<head; i++){
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}
	
	void condense(){
		max /= 2;
		int* newarr = new int[max];
		for(int i = 0; i<head; i++){
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}
	
	void append(int val){
		arr[head++] = val;
		if(head == max){
			expand();
		}
	}
	
	void remove(){
		if(head == 0){
			return;
		}
		head--;
		if(head == max/2){
			condense();
		}
	}
	
	int operator[](int idx){
		if(idx > head || idx < 0){
			return 0;
		}
		return arr[idx];
	}
	
	void printArr(){
		if(head == 0){
			cout << "Array empty." << endl;
		}
		for(int i = 0; i<head; i++){
			cout << arr[i] << endl;
		}
	}
	
};


#endif