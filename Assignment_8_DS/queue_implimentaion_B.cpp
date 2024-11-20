#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " added to the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty! Cannot delete." << endl;
            return;
        }
        Node* temp = front;
        cout << temp->data << " removed from the queue." << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Print the queue
    void print() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add (Enqueue)" << endl;
        cout << "2. Delete (Dequeue)" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.print();
                break;

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}