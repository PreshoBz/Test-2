#include <iostream>
using namespace std;

// Size of the hash table
const int TABLE_SIZE = 10;

//Hashtable class
class HashTable {
private:
    int table[TABLE_SIZE];

public:
    // Constructor: initialize all slots to -1 (empty)
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = -1;
    }

