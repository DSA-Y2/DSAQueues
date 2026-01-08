# Circular Queue 🔄

## The Problem with Arrays
Basic Array Queues are kinda mid because once you dequeue elements, that space at the front is wasted. Like, the party room is empty but the bouncer won't let new people in because the "rear" index hit the wall.

## The Fix: Circular Queue
We use math (Modulo operator `%`) to connect the end of the array back to the beginning. 

Think of it like a **Lazy Susan** or a **Roundabout**.

1. **Enqueue**: If we hit the end, we check if index 0 is free. If yes, we loop back.
2. **Dequeue**: Front moves forward, also looping back if needed.

## Key Formula
```cpp
rear = (rear + 1) % SIZE; // Next position
front = (front + 1) % SIZE; // Next position
```

## How to Run
```bash
g++ CircularQueue.cpp -o circ_q
./circ_q
```

Stay efficient. Recycle your memory.
