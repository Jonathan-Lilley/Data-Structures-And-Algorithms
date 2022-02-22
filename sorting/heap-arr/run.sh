g++ -c heap.cpp && g++ -c utility.cpp && g++ -c tests.cpp && g++ -g heap.o utility.o tests.o -o main && valgrind ./main
