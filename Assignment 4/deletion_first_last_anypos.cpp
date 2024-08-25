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
    void deleteAtFirst() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next; 
        delete temp;        
    }
    void deleteAtLast() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;  
        temp->next = nullptr;
    }
    void deleteAtPosition(int position) {
        if (position <= 0) {
            cout << "Position should be greater than 0." << endl;
            return;
        }

        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (position == 1) {
            deleteAtFirst();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position exceeds the number of nodes." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
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
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    cout << "Original List: ";
    list.display();
    list.deleteAtFirst(); 
    cout << "After deleting node at the first position: ";
    list.display();
    list.deleteAtLast(); 
    cout << "After deleting node at the last position: ";
    list.display();
    list.deleteAtPosition(2); 
    cout << "After deleting node at position 2: ";
    list.display();
    list.deleteAtPosition(10); 
    cout << "After trying to delete node at position 10: ";
    list.display();

    return 0;
}