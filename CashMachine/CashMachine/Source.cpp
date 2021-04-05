#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;
class Pair {
public:
    int Key;
    string Name;
    string Price;
    int Quant;
    void set_Key_Name(int a, string b, string c, int d) {
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
    int tableSize = 100;
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
    int HashFunc(int key) {
        /*int sum = 0;
        for (int i = 0; i < key.size(); i++)
        {
            sum += key[i];
        }
        return sum % key.size();*/
        return key;
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
    void insert(int key, string Name, string Price, int Quant) {
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
    void Search(int key)
    {
        bool flag = false;
        int hash_val = HashFunc(key);
        Node* entry = table[hash_val];
        while (entry != NULL)
        {
            if (entry->data.Key == key)
            {
                cout << "============================================" << endl;
                
                cout << "Your good: " << entry->data.Name << endl;
                cout << "Price: "<< entry->data.Price << endl;
                if (entry->data.Quant < 1) {
                    cout << "But the good is absent" << endl;
                }
                else {
                    cout << "Quant: " << entry->data.Quant << endl;
                }
                int code [10];
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
                cout << "============================================" << endl;
                cout << endl;
                flag = true;
                entry->data.Quant = entry->data.Quant - 1;
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
    HashTable machine;
    machine.insert(1, "Apple", "3", 5);
    machine.insert(2, "Grape", "4", 6);
    machine.insert(3, "Lemon", "5", 7);
    machine.insert(4, "Cheese", "6", 8);
    machine.insert(10, "Test", "100", 100);
    
    
    while (true) {
        cout << "Enter your bar: ";
        int bar;
        cin >> bar;
        machine.Search(bar);
    }
}