#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include "Check.h"
using namespace std;

class HashTable {
private:
    Node** table;
public:
    int tableSize = 20;
    float threshold = 0.8;
    int size = 0;
    int maxSize = 0;
    HashTable();
    int HashFunc(string);
    void resize();
    void insert(string, string, string, int);
    void Search(string, Check&, int);
    void checkingQuant(int, string, Check&, Node*);
    void checkForAvailability(int n, Check& receipt, Node* entry);
};