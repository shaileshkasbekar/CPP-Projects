#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create and insert a node in CSLL
Node* createCSLL(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;  // First node points to itself
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;  // Last node points to head
    }
    return head;
}

// Function to traverse CSLL
void traverseCSLL(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to insert at beginning of CSLL
Node* insertBeg(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;  // First node points to itself
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;  // Update head
    }
    return head;
}

// Function to insert at end of CSLL
Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;  // First node points to itself
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

// Function to delete from beginning of CSLL
Node* deleteBeg(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return nullptr;
    }

    Node* temp = head;
    if (head->next == head) {  // Only one node
        delete head;
        return nullptr;
    } else {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = head->next;
        head = head->next;
        delete temp;
    }
    return head;
}

// Function to delete from end of CSLL
Node* deleteEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return nullptr;
    }

    Node* temp = head;
    if (head->next == head) {  // Only one node
        delete head;
        return nullptr;
    } else {
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }
    return head;
}

// Menu-driven program for Circular Single Linked List using head
int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create\n2. Traverse\n3. Insert at Beginning\n4. Insert at End\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to create node: ";
                cin >> value;
                head = createCSLL(head, value);
                cout << "Node created.\n";
                break;

            case 2:
                cout << "CSLL contents: ";
                traverseCSLL(head);
                break;

            case 3:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                head = insertBeg(head, value);
                cout << "Node inserted at beginning.\n";
                break;

            case 4:
                cout << "Enter value to insert at end: ";
                cin >> value;
                head = insertEnd(head, value);
                cout << "Node inserted at end.\n";
                break;

            case 5:
                head = deleteBeg(head);
                cout << "Node deleted from beginning.\n";
                break;

            case 6:
                head = deleteEnd(head);
                cout << "Node deleted from end.\n";
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
