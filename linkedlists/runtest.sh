g++ -g -c tests.cpp && g++ -g -c linkedlist.cpp && g++ -g tests.o linkedlist.cpp -o tests && valgrind ./tests
