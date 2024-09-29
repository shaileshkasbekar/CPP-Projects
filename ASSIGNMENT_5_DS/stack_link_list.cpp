#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void menu() {
    cout << "1. PUSH\n2. POP\n3. PRINT\n4. EXIT\n";
}

void PUSH() {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Stack Overflow\n";
        return;
    }
    cout << "Enter value to push: ";
    cin >> newNode->data;
    newNode->next = top;
    top = newNode;
}

void POP() {
    if (top == nullptr) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << "Pop element: " << top->data << endl;
    top = top->next;
    delete temp;
}

void PRINT() {
    if (top == nullptr) {
        cout << "No Element in Stack\n";
        return;
    }
    Node* temp = top;
    cout << "Elements in stack are:\n";
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    char ch;
    do {
        menu();
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                PUSH();
                break;
            case 2:
                POP();
                break;
            case 3:
                PRINT();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid Choice\n";
                break;
        }

        cout << "\nDo you want to continue (Y/N): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
