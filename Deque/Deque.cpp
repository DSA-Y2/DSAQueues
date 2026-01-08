#include <iostream>

using namespace std;

#define MAX 5

// Deque (Double Ended Queue).
// Pronounced "Deck". It's versatile. You can add/remove from FRONT or REAR.
// It's like a tunnel, you can go in/out both ways.

class Deque {
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    // Insert at Front
    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow! Deque is stuffed." << endl;
            return;
        }

        if (front == -1) { // First element
            front = 0;
            rear = 0;
        } else if (front == 0) { // Wrap around
            front = MAX - 1;
        } else {
            front = front - 1;
        }

        arr[front] = key;
        cout << "Inserted " << key << " at Front." << endl;
    }

    // Insert at Rear
    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow! Deque is stuffed." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1) { // Wrap around
            rear = 0;
        } else {
            rear = rear + 1;
        }

        arr[rear] = key;
        cout << "Inserted " << key << " at Rear." << endl;
    }

    // Delete from Front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow! Nobody home." << endl;
            return;
        }

        cout << "Deleted " << arr[front] << " from Front." << endl;

        if (front == rear) { // Last element
            front = -1;
            rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    // Delete from Rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow! Nobody home." << endl;
            return;
        }

        cout << "Deleted " << arr[rear] << " from Rear." << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear = rear - 1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty." << endl;
            return;
        }
        cout << "Deque Elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX; // Circular movement
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5); // Should go before 10
    
    dq.display();
    
    dq.deleteFront(); // removes 5
    dq.display();
    
    dq.deleteRear();  // removes 20
    dq.display();

    return 0;
}
