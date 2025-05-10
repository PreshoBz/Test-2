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

    // Hash function: Division Method
    int hash(int key) {
      return key % TABLE_SIZE;
  }

  // Insert a key using Linear Probing
  void insert(int key) {
      int index = hash(key);         // Calculate initial index
      int originalIndex = index;     // Keep the starting index
      int i = 0;                     // Linear probing step

      // Keep probing while slot is not empty
      while (table[index] != -1) {
          cout << "Collision at index " << index << " for key " << key << endl;
          index = (originalIndex + (++i)) % TABLE_SIZE;

          // Stop if all slots are checked
          if (i == TABLE_SIZE) {
              cout << "Hash table is full. Cannot insert key " << key << endl;
              return;
          }
      }

      // Insert key when empty spot is found
      table[index] = key;
      cout << "Inserted key " << key << " at index " << index << endl;
  }

  // Display current state of the hash table
  void display() {
      cout << "\nCurrent Hash Table:\n";
      for (int i = 0; i < TABLE_SIZE; ++i) {
          cout << "Index " << i << ": ";
          if (table[i] == -1)
              cout << "EMPTY" << endl;
          else
              cout << table[i] << endl;
      }
  }
};

int main() {
  HashTable ht;

  // Step 1: Insert initial values
  int initialKeys[] = {18, 41, 22, 44, 59};
  cout << "Inserting initial keys...\n";
  for (int key : initialKeys)
      ht.insert(key);

  ht.display();  // Show table after initial insertions

  // Step 2: Insert 28 to show collision
  cout << "\nNow inserting 28 (will cause collision)...\n";
  ht.insert(28);

  ht.display();  // Final display

  return 0;
}