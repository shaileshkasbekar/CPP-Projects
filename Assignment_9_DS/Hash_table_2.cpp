#include <iostream>
using namespace std;

class HashTableLinearProbing {
private:
    int* table;
    int capacity;
    int size;

    // Hash function to calculate index
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Constructor to initialize the hash table
    HashTableLinearProbing(int cap) {
        capacity = cap;
        table = new int[capacity];
        size = 0;
        for (int i = 0; i < capacity; i++)
            table[i] = -1; // -1 indicates an empty slot
    }

    // Function to insert a key using linear probing
    void insert(int key) {
        if (size == capacity) {
            cout << "Hash table is full!" << endl;
            return;
        }
        int index = hashFunction(key);
        while (table[index] != -1) {
            index = (index + 1) % capacity; // Linear probing
        }
        table[index] = key;
        size++;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Function to search for a key
    bool search(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < capacity; i++) {
            int probeIndex = (index + i) % capacity;
            if (table[probeIndex] == key)
                return true;
            if (table[probeIndex] == -1)
                return false;
        }
        return false;
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1)
                cout << "Index " << i << ": " << table[i] << endl;
            else
                cout << "Index " << i << ": NULL" << endl;
        }
    }
};

int main() {
    HashTableLinearProbing ht(7); // Initialize hash table with size 7
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(8);

    cout << "\nHash Table with Linear Probing:" << endl;
    ht.display();

    cout << "\nSearching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}