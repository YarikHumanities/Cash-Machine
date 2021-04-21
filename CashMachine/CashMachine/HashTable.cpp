#include "HashTable.h"

HashTable::HashTable()
{
    table = new Node * [tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = NULL;
    }
}

int HashTable::HashFunc(string key) 
{
    int sum = 0;
    for (int i = 0; i < key.size(); i++)
    {
        sum += key[i];
    }
    return sum % key.size();
}

float HashTable::setThreshold(float threshold)
{
    this->threshold = threshold;
    maxSize = (int)(tableSize * threshold);
}

void HashTable::resize()
{
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

void HashTable::insert(string key, string Name, string Price, int Quant) {
    Pair aa;
    aa.set_Key_Name(key, Name, Price, Quant);
    int hash_val = HashFunc(key);
    Node* prev = NULL;
    Node* entry = table[hash_val];
    while (entry != NULL) 
    {
        prev = entry;
        entry = entry->next;
    }
    if (entry == NULL) 
    {
        entry = new Node(aa);
        if (prev == NULL) {
            table[hash_val] = entry;
            size++;
        }
        else {
            prev->next = entry;
        }
    }
    else 
    {
        entry->data.Name;
        size++;
    }
    if (size >= maxSize) 
    {
        resize();
    }
}


void HashTable::Search(string key, Check& recipe, int n)
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
                    recipe.list_of_names += entry->data.Name + " (x" + temp_n + ") ";
                }
                else {
                    recipe.list_of_names += entry->data.Name + " ";
                }
                int temp_sum;
                temp_sum = stoi(entry->data.Price) * n;
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