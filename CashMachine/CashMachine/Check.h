#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

class Check {
public:
    string list_of_names;
    int sum;
    Check();
    void print_receipt();
};