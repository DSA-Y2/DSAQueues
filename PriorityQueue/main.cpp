#include <iostream>

// Priority Queue (max-heap) using a simple array.
// Only uses iostream to keep it beginner-friendly.

class PriorityQueue {
public:
    explicit PriorityQueue(int capacity) {
        cap = capacity;
        data = new int[cap];
        sz = 0;
    }

    ~PriorityQueue() {
        delete[] data;
    }

    bool isEmpty() const {
        return sz == 0;
    }

    bool isFull() const {
        return sz == cap;
    }

    // Insert a value and bubble it up.
    bool push(int value) {
        if (isFull()) {
            return false;
        }

        // Place the new value at the end.
        data[sz] = value;
        int idx = sz;
        sz++;

        // Bubble up: swap with parent while bigger.
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (data[parent] >= data[idx]) {
                break;
            }
            // Swap parent and child.
            int temp = data[parent];
            data[parent] = data[idx];
            data[idx] = temp;

            idx = parent;
        }

        return true;
    }

    // Remove and return the biggest value (root).
    bool pop(int &outValue) {
        if (isEmpty()) {
            return false;
        }

        outValue = data[0];
        sz--;

        // Move last element to root.
        data[0] = data[sz];

        // Bubble down: swap root with larger child until heap property holds.
        int idx = 0;
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < sz && data[left] > data[largest]) {
                largest = left;
            }
            if (right < sz && data[right] > data[largest]) {
                largest = right;
            }

            if (largest == idx) {
                break;
            }

            // Swap idx with largest child.
            int temp = data[idx];
            data[idx] = data[largest];
            data[largest] = temp;

            idx = largest;
        }

        return true;
    }

    // Peek the biggest value without removing.
    bool top(int &outValue) const {
        if (isEmpty()) {
            return false;
        }

        outValue = data[0];
        return true;
    }

    // Print the heap as a flat array (for learning/debug).
    void print() const {
        std::cout << "Heap (array view): ";
        if (isEmpty()) {
            std::cout << "[empty]" << std::endl;
            return;
        }

        for (int i = 0; i < sz; i++) {
            std::cout << data[i];
            if (i + 1 < sz) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

private:
    int* data;
    int cap;
    int sz;
};

int main() {
    // Demo: Priority Queue (max-heap)
    PriorityQueue pq(10);

    std::cout << "Priority Queue (Max-Heap) Demo\n";

    // Push some values.
    pq.push(5);
    pq.push(20);
    pq.push(15);
    pq.push(30);
    pq.push(10);
    pq.print();

    // Peek the max.
    int maxVal;
    if (pq.top(maxVal)) {
        std::cout << "Top (max) is: " << maxVal << "\n";
    }

    // Pop the max repeatedly.
    while (!pq.isEmpty()) {
        int removed;
        if (pq.pop(removed)) {
            std::cout << "Popped: " << removed << "\n";
        }
        pq.print();
    }

    // If you want to see error handling, uncomment this:
    // int dummy;
    // pq.pop(dummy);

    return 0;
}
