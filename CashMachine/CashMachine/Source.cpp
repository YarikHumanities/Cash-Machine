#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Function.h"
#include "HashTable.h"
using namespace std;

int main() {
    srand(time(NULL));
    ifstream inFile;
    string path = "Doc.txt";
    HashTable machine;
<<<<<<< Updated upstream
    fileWork(path, machine);
    return 0;
=======
    inFile.open(path);
    if (!inFile.is_open()) {
        std::cout << "Cannot open the doc" << std::endl;
    }
    else
    {
       // std::cout << "Doc is opened" << std::endl;
        while (!inFile.eof())
        {
            string str;
            getline(inFile, str);
            string bar;
            string name;
            string price;
            int count;
            bar= string(str, str.find("barcode:")+8, str.find("name")-1 -str.find("barcode:")-8);
            name= string(str, str.find("name:") + 5, str.find("price:") - 1 - str.find("name:")-5);
            price= string(str, str.find("price:") + 6, str.find("quant:") - 1 - str.find("price:") - 6);
            count = stoi(string(str, str.find("quant:") + 6, str.size() - 1 - str.find("quant:")));

            //cout << str.find("name:") << endl;
            //cout << str<<endl;
            /*cout << "Bar= " << bar <<endl;
            cout << "Name= " << name << endl;
            cout << "Price= " << price <<endl;*/
            machine.insert(bar,name, price, count);
        }
    }
   /* machine.insert("0001", "Apple", "3", 3);
    machine.insert("0002", "Grape", "4", 6);
    machine.insert("0003", "Lemon", "5", 7);
    machine.insert("0004", "Cheese", "6", 8);
    machine.insert("0005", "Test", "100", 100);
    machine.insert("0006", "Test1", "10", 10);
    machine.insert("0007", "Test2", "250", 10);
    machine.insert("0008", "Test3", "310", 115);
    machine.insert("0009", "Test4", "43", 98);*/
    while (true) {
        cout << "Hello customer!" << endl;
        Check recipe;
        while (true) {
            cout << "Enter your bar (or enter Exit): ";
            string bar;
            cin >> bar;
            if (bar == "Exit") {
                break;
            }
            int n;
            cout << "Enter quantity of a good: ";
            cin >> n;
            cin.ignore();
            
            machine.Search(bar, recipe, n);
            
        }
        cout << "=========================" << endl;
        recipe.print_recipe();
        int code[10];
        for (int i = 0; i < 10; i++)
        {
            code[i] = rand() % 10;
        }
        cout << "Code for payment: " << endl;
        cout << "#";
        for (int i = 0; i < 10; i++)
        {
            cout << code[i];
        }
        cout << endl;
        cout << "=========================" << endl;
    }
>>>>>>> Stashed changes
}