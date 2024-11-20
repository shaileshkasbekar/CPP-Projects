#include <iostream>
#include <list>
using namespace std;

class HashTableChaining {
private:
    int capacity; // Size of the hash table
    list<int>* table; // Array of linked lists

    // Hash function to map values to key
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Constructor to initialize the hash table
    HashTableChaining(int size) {
        capacity = size;
        table = new list<int>[capacity];
    }

    // Function to insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Function to remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
        cout << "Removed " << key << " from index " << index << endl;
    }

    // Function to search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        for (auto x : table[index]) {
            if (x == key)
                return true;
        }
        return false;
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Index " << i << ": ";
            for (auto x : table[i]) {
                cout << x << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTableChaining ht(7); // Initialize hash table with size 7
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(8);

    cout << "\nHash Table with Chaining:" << endl;
    ht.display();

    cout << "\nSearching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    ht.remove(15);
    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}