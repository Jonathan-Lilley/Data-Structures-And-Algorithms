g++ -g -c sbbst.cpp && g++ -g -c tests.cpp && g++ -g sbbst.o tests.o -o main && valgrind ./main
