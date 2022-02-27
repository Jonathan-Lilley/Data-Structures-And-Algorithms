g++ -c levenshtein.cpp && g++ -c tests.cpp && g++ -g levenshtein.o tests.o -o main && valgrind ./main
