#include <iostream>

using namespace std;

// No fancy headers, just raw logic.
// Basic Queue using an Array. FIFO vibes.

#define MAX_SIZE 100 // Cap for the queue. Don't overflow the drip.

class ArrayQueue {
    int arr[MAX_SIZE];
    int front; // Pointer to the front of the line
    int rear;  // Pointer to the back of the line

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is fully booked
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // Check if the queue is empty (ghost town)
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Add elements to the queue (Join the line)
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow! Too many people at the party." << endl;
            return;
        }
        if (front == -1) front = 0; // First person joining
        rear++;
        arr[rear] = val;
        cout << "Enqueued " << val << " into the queue." << endl;
    }

    // Remove elements from the queue (Leave the party)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Ain't nobody here." << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << " from the queue." << endl;
        front++;
        
        // Reset if everyone left
        if (isEmpty()) {
            front = -1;
            rear = -1;
        }
    }

    // Peek at the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty using peek." << endl;
            return -1;
        }
        return arr[front];
    }

    // Show everyone in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue content: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q;
    
    // Testing the vibes
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.display();
    
    q.dequeue();
    q.display();
    
    cout << "Front element is: " << q.peek() << endl;

    return 0;
}
