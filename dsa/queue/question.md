## Introduction to Question

A Queue Data Structure is a fundamental concept in computer science used for storing and managing data in a specific order. It follows the principle of "First in, First out" (FIFO), where the first element added to the queue is the first one to be removed.

The task is to implement the basic queue operations (Enqueue and Dequeue) and to explore different types of queues, including **Linear Queue**, **Circular Queue**, and **Priority Queue**. This exercise will help you understand the queue data structure, its variations, and practical applications in managing and prioritizing data.

## 1: Implement Basic Queue Operations

1. **Queue Implementation**:
   - Write a C++ program to implement a queue data structure.
   - The queue should support the following operations:
     - `Enqueue`: Add an element to the rear of the queue.
     - `Dequeue`: Remove and return the front element of the queue.
     - `isEmpty`: Check if the queue is empty.
     - `isFull`: Check if the queue is full (applicable for array-based queue).
     - `Peek`: Return the front element without removing it.

2. **Error Handling**:
   - Handle cases where `Dequeue` or `Peek` is called on an empty queue.
   - Ensure proper memory management for dynamically allocated queues.

---

## 2: Implement Different Types of Queues

### 1. Linear Queue
   - Implement a linear queue using an array or linked list.
   - Demonstrate enqueueing and dequeueing operations.
   - Discuss limitations of the linear queue, especially the issue of unused space as elements are dequeued.

### 2. Circular Queue
   - Implement a circular queue using an array.
   - Modify the `Enqueue` and `Dequeue` operations to allow the queue to wrap around when it reaches the end of the array.
   - Ensure that the circular queue efficiently uses available space and handles the wrap-around condition correctly.
   - Implement functions to check if the queue is empty or full.

### 3. Priority Queue
   - Implement a priority queue using an array, linked list, or heap.
   - Assign each element a priority value, with lower values indicating higher priority.
   - Ensure that `Dequeue` removes the element with the highest priority (lowest value).
   - Implement functions to add an element with a given priority and to remove elements based on priority.


## Guidelines

- **Documentation**: Comment each function, explaining its purpose and steps.
- **Error Handling**: Include checks for invalid operations on empty or full queues.
- **Testing**: Add test cases to demonstrate different queue operations and scenarios for each type of queue.


## Submission

- Submit separate files for each queue type if needed (`linear_queue.cpp`, `circular_queue.cpp`, `priority_queue.cpp`), or combine them into one program with different classes for each type.
- Add example test cases in `main()` to showcase the functionality for each queue type.
- Include comments for readability and maintainability of the code.
