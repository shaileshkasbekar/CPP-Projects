#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    void insertAtFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Position should be greater than 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position is greater than the number of nodes. Inserting at the end." << endl;
            insertAtEnd(value);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);     
    list.insertAtEnd(20);     
    list.insertAtEnd(30);     

    cout << "Original List: ";
    list.display();

    list.insertAtFirst(5);    
    cout << "After inserting 5 at the first position: ";
    list.display();

    list.insertAtEnd(40);     
    cout << "After inserting 40 at the last position: ";
    list.display();

    list.insertAtPosition(25, 3);  
    cout << "After inserting 25 at position 3: ";
    list.display();

    list.insertAtPosition(50, 10); 
    cout << "After inserting 50 at position 10 (beyond the end): ";
    list.display();

    return 0;
}