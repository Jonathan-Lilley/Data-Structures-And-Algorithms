#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H
#include <string>

void constructTable(std::string, std::string, int*);

int levDist(std::string, std::string, int, int, int*);

#endif