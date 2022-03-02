#include <string>
#include <iostream>
#include <time.h>
#include "queue.h"
#include "graph.h"
#include "searches.h"

using namespace std;

int main() {
	cout << endl;
	srand(time(NULL));
	int count = 7;
	
	string names[count] = { "Lion" , "Rabbit", "Dog", "Otter", "Raccoon", "Dragon", "Tiger" };
	int connections[count*count];
	for(int i = 0; i < count; i++) {
		for(int j = 0; j < count; j++ ){
			if(j == i) {
				connections[i*count+j] = 0;
			}
			else {
				connections[i*count+j] = rand() % 2;
			}
		}
	}
	
	Graph* animals = newGraph(count, names, connections);
	printAllNodes(animals);
	cout << endl;
	
	printNeighborNodes(animals);
	cout << endl;
	
	cout << "Breadth first search" << endl;
	int found = breadthFirst(animals,"Tiger");
	Node* animal = getNode(animals,found);
	cout << animal->name << endl;
	cout << endl;
	
	cout << "Depth first search" << endl;
	found = depthFirst(animals,"Tiger");
	animal = getNode(animals,found);
	cout << animal->name << endl;
	
	deleteGraph(animals);
	cout << endl;
}