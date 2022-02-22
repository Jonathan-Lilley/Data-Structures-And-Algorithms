#ifndef HEAP_H
#define HEAP_H

int parent(int);

int left(int);

int right(int);

bool validateHeap(int[], int, int, bool);

void heapify(int[], int, int, bool);

void heapifyArr(int[], int, bool);

void heapSort(int[], int, bool);

#endif