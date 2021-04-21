#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

class Pair {
public:
    string Key;
    string Name;
    string Price;
    int Quant;
    void set_Key_Name(string, string, string, int);
};