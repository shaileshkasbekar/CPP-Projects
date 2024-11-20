#include <iostream>
using namespace std;
class CircularQueue {
private:
    int *queue;
    int front, rear, size;
public:
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % size == front) return;
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        queue[rear] = value;
    }

    void dequeue() {
        if (front == -1) return;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }

    void print() {
        if (front == -1) return;
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    int size, choice, value;

    cin >> size;
    CircularQueue cq(size);

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.print();
                break;
            case 4:
                return 0;
        }
    }

    return 0;
}