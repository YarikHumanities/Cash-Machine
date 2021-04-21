#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "Pair.h"
using namespace std;

class Node {
public:
    Pair data;
    Node* next;
    Node(Pair);
};