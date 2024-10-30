## Introduction to Question

A Stack is a linear data structure that follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out). LIFO implies that the element that is inserted last, comes out first and FILO implies that the element that is inserted first, comes out last.

The task is to implement basic stack operations and create algorithms that convert an **infix expression** to **postfix** and **prefix** expressions. This exercise will help you understand stack data structures and their practical applications in expression evaluation and conversion.

## 1: Implement Stack Operations

1. **Stack Implementation**: 
   - Write a C++ program to implement a stack data structure.
   - The stack should support the following operations:
     - `Push`: Add an element to the top of the stack.
     - `Pop`: Remove and return the top element of the stack.
     - `Peek`: Return the top element without removing it.
     - `isEmpty`: Check if the stack is empty.
     - `isFull` (if using an array-based stack): Check if the stack is full.

2. **Error Handling**:
   - Handle cases where `Pop` or `Peek` is called on an empty stack.
   - Ensure proper memory management if using a dynamic stack.

---

##  2: Convert Infix Expression to Postfix and Prefix

1. **Infix to Postfix Conversion**:
   - Implement a function to convert an infix expression (e.g., `A + B * C`) to a postfix expression (e.g., `A B C * +`).
   - Use the stack to handle operators and ensure the correct order of operations based on precedence.
   - Handle expressions with `+`, `-`, `*`, `/`, and `^` operators and parentheses.

2. **Infix to Prefix Conversion**:
   - Implement a function to convert an infix expression to a prefix expression (e.g., `A + B * C` becomes `+ A * B C`).
   - Use a stack-based algorithm similar to the postfix conversion but modified for prefix notation.

3. **Evaluation of Postfix and Prefix Expressions** (Optional):
   - Implement functions to evaluate postfix and prefix expressions. These functions should return the calculated result of a valid postfix or prefix expression.


## Guidelines

- **Documentation**: Comment each function, explaining its purpose and steps.
- **Error Handling**: Include checks for invalid expressions and empty stack operations.
- **Testing**: Add test cases to demonstrate different types of expressions (simple, complex with parentheses, etc.).


## Submission

- Submit a `like: stack_operations.cpp` file containing the stack operations and conversion algorithms.
- Add example test cases in `main()` to showcase the functionality.
- Include comments for readability and maintainability of the code.

