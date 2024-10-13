#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Push operation to add an element to the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack.\n";
    }

    // Pop operation to remove the top element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow! No element to pop.\n";
            return;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped: " << poppedValue << endl;
    }

    // Print all elements in the stack
    void print() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free up memory
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Print\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.print();
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}