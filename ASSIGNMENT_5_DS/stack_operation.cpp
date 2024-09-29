#include <iostream>
using namespace std;
#define MAX 100

int stack[MAX];  
int top = -1; 
void push() {
    if (top == MAX - 1) {
        cout << "Stack overflow! Cannot push more elements." << endl;
    } else {
        int element;
        cout << "Enter the element to push: ";
        cin >> element;
        stack[++top] = element;
        cout << element << " pushed onto the stack." << endl;
    }
}
void pop() {
    if (top == -1) {
        cout << "Stack is empty! Cannot pop." << endl;
    } else {
        cout << stack[top--] << " popped from the stack." << endl;
    }
}
void print_stack() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack contents: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}
void menu() {
    int choice;
    do {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print_stack();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);
}
int main() {
    int size;
    cout<<"enter size of array"<<endl;
    menu();
    return 0;
}