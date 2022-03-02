g++ -c graph.cpp && g++ -c searches.cpp && g++ -c queue.cpp && g++ -c tests.cpp && g++ -c stack.cpp &&
g++ -g graph.o searches.o queue.o stack.o tests.o -o main && valgrind ./main 
