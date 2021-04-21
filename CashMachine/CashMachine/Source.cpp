#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Function.h"
#include "HashTable.h"
using namespace std;

int main() 
{
    srand(time(NULL));
    ifstream inFile;
    string path = "Doc.txt";
    HashTable machine;
    fileWork(path, machine);
    return 0;
}