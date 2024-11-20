#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
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
                q.push(value);
                cout << value << " added to the queue." << endl;
                break;

            case 2:
                if (!q.empty()) {
                    cout << q.front() << " removed from the queue." << endl;
                    q.pop();
                } else {
                    cout << "Queue is empty! Cannot delete." << endl;
                }
                break;

            case 3:
                if (!q.empty()) {
                    cout << "Queue elements: ";
                    queue<int> temp = q;
                    while (!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                } else {
                    cout << "Queue is empty!" << endl;
                }
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