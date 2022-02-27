#include <iostream> 
#include "levenshtein.h"

using namespace std;

void constructTable(string sOne, string sTwo, int* distances) {
	int idx;
	cout << "Distance table: " << endl;
	cout << "   ";	
	for(char c:  sOne) {
		cout << c << "   ";
	}
	cout << endl;
	for(int j = 0; j < sTwo.length(); j++) {
		cout << sTwo[j] << "  ";
		for(int i = 0; i < sOne.length(); i++) {
			idx = (i*sTwo.length())+j;
			cout << *(distances+idx);
			cout << " ";
			if(*(distances+idx) < 10) {
				cout << " ";
			}
			if((*(distances+idx) < 100) && (*(distances+idx) >= 0)) {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}



int levDist(string sOne, string sTwo, int currOne, int currTwo, int* distances) {
	int idx = (currOne*sTwo.length())+currTwo;
	
	if(*(distances+idx) > -1) {
		return *(distances+idx);
	}
	
	
	int comp = 0;
	if(sOne[currOne] != sTwo[currTwo] || currOne != currTwo) {
		comp = 1;
	}
	
	if(currOne == 0 && currTwo == 0) {
		*(distances+idx) = comp;
		return *(distances+idx);
	}
	
	else if(currOne == 0) {
		*(distances+idx) = comp + levDist(sOne, sTwo, currOne, currTwo-1, distances);
		return *(distances+idx);
	}
	
	
	else if(currTwo == 0) {
		*(distances+idx) = comp + levDist(sOne, sTwo, currOne-1, currTwo, distances);
		return *(distances+idx);
	}
	
	else {
		int del = levDist(sOne, sTwo, currOne, currTwo-1, distances);
		int ins = levDist(sOne, sTwo, currOne-1, currTwo, distances);
		int rep = levDist(sOne, sTwo, currOne-1, currTwo-1, distances);
		
		int min = ins + del + rep + 1;
		
		if(ins < min) {
			min = ins;
		}
		if(del < min) {
			min = del;
		}
		if(rep < min) {
			min = rep;
		}
		min += comp;
		*(distances+idx) = min;
		
		
		return min;
	}
}