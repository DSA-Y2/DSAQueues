#include <iostream>

using namespace std;

// Linked List Queue implementation.
// infinite storage (until RAM cries).

struct Node {
    int data;
    Node* next;
};

class LinkedListQueue {
    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = NULL;
        rear = NULL;
    }

    // Add to the queue
    void enqueue(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        // If queue is empty, new node is both front and rear
        if (front == NULL) {
            front = rear = newNode;
        } else {
            // Add to the end, update rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << val << " (Linked List style)." << endl;
    }

    // Remove from the queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! Nothing to yeet." << endl;
            return;
        }
        
        Node* temp = front;
        cout << "Dequeued " << front->data << endl;
        front = front->next;

        // If front becomes NULL, rear should also be NULL
        if (front == NULL) {
            rear = NULL;
        }

        delete temp; // Clean up memory, don't be messy
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty (Literally 0 nodes)." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedListQueue q;
    
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    
    q.display();
    
    q.dequeue();
    q.display();

    return 0;
}
