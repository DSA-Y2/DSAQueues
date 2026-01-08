# Deque (Double Ended Queue) ↔️

This isn't a normal queue. It's a **Deque** (pronounced "Deck").

## The Vibe
In a normal queue, you only enter from the back and leave from the front. 
In a Deque, you can do whatever you want. 

- **Insert Front**: Cutting the line (permitted here).
- **Insert Rear**: Acting normal.
- **Delete Front**: Acting normal.
- **Delete Rear**: Changing your mind and leaving before you get served.

## Why use it?
It's flexible. Used in things like:
- Undo operations (Ctrl+Z)
- Browser history
- A-Steal (Job scheduling algorithms)

## Important
This implementation is also **Circular** internally to save space. So it wraps around if it hits the array limit.

## How to Run
```bash
g++ Deque.cpp -o deque
./deque
```
