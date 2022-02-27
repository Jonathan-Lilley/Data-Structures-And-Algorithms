#include <iostream>
#include <string.h>
#include "levenshtein.h"

using namespace std;

int main(int argc, char** argv) {
	string sone = "alph";
	string stwo = "apbhat";
	int distlen = sone.length()*stwo.length();
	
	int* distances = new int[distlen];
		
	for(int i = 0; i < distlen; i++) {
		*(distances+i) = -1;
	}
	
	cout << endl;
	
	cout << "Words: " << sone << ", " << stwo << endl;
	
	cout <<  "Distance: " << levDist(sone, stwo, sone.length()-1, stwo.length()-1, distances) << endl << endl;

	
	constructTable(sone, stwo, distances);
	
	delete distances;
}