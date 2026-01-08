#include <iostream>

using namespace std;

#define SIZE 5

// Circular Queue because we don't like wasting space.
// It recycles the empty spots at the beginning like eco-friendly vibes.

class CircularQueue {
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        // Two cases for full:
        // 1. front is 0 and rear is at the end.
        // 2. front is right ahead of rear (caught up).
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is Full! Stop spamming." << endl;
        } else {
            if (front == -1) front = 0; // First element
            
            // Circular increment: (rear + 1) % SIZE
            // If rear is at end and we have space at start, it wraps around.
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Ghost town." << endl;
        } else {
            int element = items[front];
            cout << "Deleted " << element << endl;
            
            if (front == rear) {
                // Reset queue if it was the last element
                front = -1;
                rear = -1;
            } else {
                // Move front forward (or wrap around)
                front = (front + 1) % SIZE;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty Queue" << endl;
            return;
        }
        cout << "Items -> ";
        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE)
            cout << items[i] << " ";
        cout << items[i] << endl;
    }
};

int main() {
    CircularQueue cq;

    cq.dequeue(); // Fail check

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    // Fails because SIZE is 5
    cq.enqueue(6);

    cq.display();

    cq.dequeue(); // remove 1
    cq.display();

    cq.enqueue(7); // Should wrap around to index 0
    cq.display();

    return 0;
}
