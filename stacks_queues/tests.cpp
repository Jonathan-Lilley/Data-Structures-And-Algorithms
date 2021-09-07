#include <iostream>
#include "dynarr.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){
	
	/*
	int arr2[] = {1, 2, 3, 4, 5, 6, 7};
	
	
	DynArr arr1 = DynArr();
	for(int i = 0; i < 10; i++){
		arr1.append(i);
	}
	cout << arr1[9] << endl;
	cout << arr1[20] << endl;
	arr1.printArr();
	
	
	DynArr arr3 = DynArr(arr2,sizeof(arr2)/sizeof(arr2[0]));
	for(int i = 0; i < 10; i++){	
		arr3.remove();		
	}
	arr3.printArr();
	*/
	
	/*
	Stack stack1 = Stack(10);
	for(int i = 0; i < 12; i++){
		stack1.push(i);
	}
	for(int i = 0; i < 12; i++){
		cout << stack1.pop() << endl;
	}
	*/
	
	Queue queue1 = Queue(10);
	for(int i = 0; i < 12; i++){
		//cout << i << endl;
		queue1.enqueue(i);
	}	
	for(int i = 0; i < 12; i++){
		cout << queue1.dequeue() << endl;
	}
	
	return 0;
}