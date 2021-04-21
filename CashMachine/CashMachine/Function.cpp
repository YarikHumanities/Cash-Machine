#include "Function.h"

void printCodeForCheck()
{
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

void interface(HashTable& CashMachine)
{
    while (true) {
        cout << "Hello customer!" << endl;
        Check receipt;
        while (true) {
            cout << "Enter your bar (or enter Exit): ";
            string bar;
            cin >> bar;
            if (bar == "Exit" || bar == "exit")
                break;
            int n;
            cout << "Enter quantity of a good: ";
            cin >> n;
            if (n == 0)
            {
                cout << "Quantity cannot be zero! Repeat!" << endl << "Quantity of a good: ";
                cin >> n;
            }
            cin.ignore();
            CashMachine.Search(bar, receipt, n);
        }
        cout << "=========================" << endl;
        receipt.print_receipt();
        printCodeForCheck();
    }
}

void fileWork(string fileName, HashTable& CashMachine)
{
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open())
        std::cout << "Cannot open the doc" << std::endl;
    else
    {
        while (!inFile.eof())
        {
            string str;
            getline(inFile, str);
            string bar;
            string name;
            string price;
            int count;
            bar = string(str, str.find("barcode:") + 8, str.find("name") - 1 - str.find("barcode:") - 8);
            name = string(str, str.find("name:") + 5, str.find("price:") - 1 - str.find("name:") - 5);
            price = string(str, str.find("price:") + 6, str.find("quant:") - 1 - str.find("price:") - 6);
            count = stoi(string(str, str.find("quant:") + 6, str.size() - 1 - str.find("quant:")));
            CashMachine.insert(bar, name, price, count);
        }
        interface(CashMachine);
    }
    inFile.close();
}