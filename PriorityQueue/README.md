# Priority Queue - but make it simple

Yo. This folder shows a **Priority Queue** in C++.

A priority queue is like a VIP line:
- Items don’t just leave in the order they arrived.
- The **highest priority** (or biggest value) leaves first.

That’s why it’s **not FIFO** — it’s **priority-based**.

## What type of priority queue is this?
This is a **max-heap** using a simple array.

### Why a heap?
Because we want:
- **Insert (push)**: `O(log n)`
- **Extract max (pop)**: `O(log n)`
- **Peek max**: `O(1)`

A heap keeps the biggest element at the root (index 0) and lets us bubble things up/down efficiently.

## Operations
- **push(x)**: add `x` and bubble it up to its correct spot
- **pop()**: remove and return the biggest element
- **top()**: peek the biggest element (no removing)
- **isEmpty()**: nothing inside?
- **print()**: show the heap as a flat array (for learning)

## Big-O (performance vibes)
- **push**: `O(log n)`
- **pop**: `O(log n)`
- **top/peek**: `O(1)`

## Files you’ll see
- `main.cpp`: full implementation + demo (no extra headers)

## How to run
From this folder:

```bash
g++ -std=c++17 main.cpp -o priority_queue_demo
./priority_queue_demo
```

Windows (MinGW):

```bash
priority_queue_demo.exe
```

## Quick mental model
- Parent of index `i` is at `(i - 1) / 2`
- Left child: `2 * i + 1`
- Right child: `2 * i + 2`

When you push, you **bubble up**.
When you pop, you swap root with the last element, then **bubble down**.

## Common mistakes
- Forgetting to update size after pop
- Off-by-one errors in parent/child math
- Not maintaining the heap property after swaps
