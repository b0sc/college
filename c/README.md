# C

<img align="right" width="300" src="./assets/padhate-kaise-hain.jpg" alt="clone this repository" />

> Theory part covers topics like data types, operators, control structures, functions, arrays, pointers, strings, file handling, structures, and unions.

> This course is designed to help students understand the practical implementations of those thoeritical concepts taught in syllabus.

## How to Submit?

Inside the `[taskname]` folder, there is a `README.md` file that you will write, how the task was implemented. Code in any of `C, Go, Python, Java, C++, C#, JavaScript, PHP` extension file. You can follow this same format to submit your task.

-   Introduction to Question
-   Propose a solution
-   Explanation of the code
-   Output of the code `screenshots`.

When done, there should be two files in the `[taskname]` folder: `README.md` and the code file `[taskname].c` and any required pictures in the `assets` folder.

## Tasks

You're free to write in `C, Go, Python, Java, C++, C#, JavaScript, PHP` or any other language you prefer, once understood the concept, you can implement it in any language you like.

-   [ ] [Sqrt](./sqrt/)
-   [ ] [Cash](./cash/)
-   [ ] [Longer](./longer/)
-   [ ] [Task 4 TBD]()
-   [ ] [Task 5 TBD]()
-   [ ] [Task 6 TBD]()
-   [ ] [Task 7 TBD]()
-   [ ] [Task 8 TBD]()
-   [ ] [Task 9 TBD]()
-   [ ] [Task 10 TBD]()

### Task 1: Sqrt

A program to calculate the square root of a number without using the sqrt() function from the math library. Your program should include the following:

-   Handle special cases like negative numbers and 0.
-   Ensure the approximation continues until the result is accurate up to 6 decimal places.
-   Return the result of the square root calculation as a double.

_Hint:Newton-Raphson method_

### Task 2: Cash

A program that calculates the minimum number of coins required to give a user change. Your program should include the following:

-   Prompt the user for the amount of change owed.
-   Calculate the minimum number of coins with which that change can be made.
-   Use the following coin denominations: 25¢, 10¢, 5¢, and 1¢.

_Hint: Greedy Algorithm_. Check [here](https://cs50.harvard.edu/x/2024/psets/1/cash/) for more details.

### Task 3: Longer

A program to compute the result of two large numbers that cannot be stored in standard data types like int or long. Implement addition, subtraction, and multiplication of these large numbers by simulating how the operations work at the digit level. Your program should include the following:

-   Represent the large numbers using arrays (or dynamically allocated memory).
-   Implement functions for addition, subtraction, and multiplication that work digit-by-digit, similar to how manual calculations are done.
-   Handle both positive and negative numbers.
-   Ensure proper handling of overflow for large numbers beyond standard data type limits.

_Hint: Memory Management_
