#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;
class Check {
public:
    string list_of_names;
    int sum;
    Check() {
        list_of_names = "";
        sum = 0;
    }
    void print_recipe(){
        cout << "Goods: " << list_of_names << endl;
        cout << "Sum: " << sum << endl;
    }
};
class Pair {
public:
    string Key;
    string Name;
    string Price;
    int Quant;
    void set_Key_Name(string a, string b, string c, int d) 
    {
        Key = a;
        Name = b;
        Price = c;
        Quant = d;
    }
};
//Linked list
class Node {
public:
    Pair data;
    Node* next;
    Node(Pair x) {
        data = x;
        next = NULL;
    }
};
class LinkedList {
public:
    Node* head;
    bool isEmpty() {
        if (head == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void addAtEnd(Pair pair) {
        Node* n = new Node(pair);
        if (head == NULL) {
            head = n;
            n->next = NULL;
        }
        else {
            Node* n2 = getLastNode();
            n2->next = n;
        }
    }
    Node* getLastNode() {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        return ptr;
    }
    LinkedList() {
        head = NULL;
    }
};
//Hash table
class HashTable {
private:
    Node** table;
public:
    int tableSize = 10;
    float threshold = 0.8;
    int size = 0;
    int maxSize = 0;
    HashTable() {
        table = new Node * [tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = NULL;
        }
    }
    int HashFunc(string key) {
        int sum = 0;
        for (int i = 0; i < key.size(); i++)
        {
            sum += key[i];
        }
        return sum % key.size();
       // return key;
    }
    float setThreshold(float threshold) {
        this->threshold = threshold;
        maxSize = (int)(tableSize * threshold);
    }
    void resize() {
        int OldTableSize = tableSize;
        tableSize *= 2;
        maxSize = (int)(tableSize * threshold);
        Node** OldTable = table;
        table = new Node * [tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = NULL;
        }
        size = 0;
        for (int hash = 0; hash < OldTableSize; hash++)
        {
            if (OldTable[hash] != NULL) {
                Node* oldEntry;
                Node* entry = OldTable[hash];
                while (entry != NULL) {
                    insert(entry->data.Key, entry->data.Name, entry->data.Price, entry->data.Quant);
                    oldEntry = entry;
                    entry = entry->next;
                    delete oldEntry;
                }
            }
        }
        delete[] OldTable;
    }
    void insert(string key, string Name, string Price, int Quant) {
        Pair aa;
        aa.set_Key_Name(key, Name, Price, Quant);
        int hash_val = HashFunc(key);
        Node* prev = NULL;
        Node* entry = table[hash_val];
        while (entry != NULL) {
            prev = entry;
            entry = entry->next;
        }
        if (entry == NULL) {
            entry = new Node(aa);
            if (prev == NULL) {
                table[hash_val] = entry;
                size++;
            }
            else {
                prev->next = entry;
            }
        }
        else {
            entry->data.Name;
            size++;
        }
        if (size >= maxSize) {
            resize();
        }
    }
    void Search(string key, Check& recipe, int n)
    {
        bool flag = false;
        int hash_val = HashFunc(key);
        Node* entry = table[hash_val];
        while (entry != NULL)
        {
            if (entry->data.Key == key)
            {
                if (n > entry->data.Quant) {
                    cout << "There is a lack of " << entry->data.Name << "s" << " in quantity of " << n - entry->data.Quant << endl;
                    return;
                }
               
                if (entry->data.Quant < 1) {
                    cout << "But the good is absent" << endl;
                }
                else {
                    if (n > 1) {
                        string temp_n = to_string(n);
                        recipe.list_of_names += entry->data.Name + " (x"+temp_n+") ";
                    }
                    else {
                        recipe.list_of_names += entry->data.Name + " ";
                    }
                    int temp_sum;
                    temp_sum = stoi(entry->data.Price)*n;
                    recipe.sum += temp_sum;
                }
               
                flag = true;
                entry->data.Quant = entry->data.Quant - n;
            }
            entry = entry->next;
        }
        if (!flag)
        {
            cout << "There isn't such a good in our supermarket" << endl;
        }
    }
};
int main() {
    srand(time(NULL));
    ifstream inFile;
    string path = "G:/lab rep/Cash-Machine/CashMachine/CashMachine/Doc.txt";
    HashTable machine;
    inFile.open(path);
    if (!inFile.is_open()) {
        std::cout << "Cannot open the doc" << std::endl;
    }
    else
    {
        std::cout << "Doc is opened" << std::endl;
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
}