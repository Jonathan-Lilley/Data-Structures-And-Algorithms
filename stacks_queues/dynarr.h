#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynArr {

private:
	int* arr;
	int head;
	int max;

public:
	DynArr();
	DynArr(int, int);
	~DynArr();
	void expand();
	void condense();
	void append(int val);
	void remove();
	int operator[](int idx);
	void printArr();
	}

};
