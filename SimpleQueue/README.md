# Simple Queue 101 🚦

Yo, welcome to the basic Queue zone. 

## What's a Queue?
Imagine a line at a Starbucks or waiting for a sneaker drop. It's **FIFO** - **First In, First Out**. 

- The first person in line gets served first.
- If you cut the line, you get cancelled (not supported here).

## Operations
- **Enqueue**: Joining the back of the line.
- **Dequeue**: Getting served and leaving the front.
- **Peek**: Seeing who's next without removing them.

## Files
1. **ArrayQueue.cpp**: Uses a fixed-size array. Fast but has a limit (like a VIP club capacity).
2. **LinkedListQueue.cpp**: Uses pointers. Dynamic size (invites everyone until the house explodes).

## How to Run (if you have g++):
```bash
g++ ArrayQueue.cpp -o array_q
./array_q
```
or 
```bash
g++ LinkedListQueue.cpp -o ll_q
./ll_q
```

No cap, just basic data structures.
