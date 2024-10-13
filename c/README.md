# C

<img align="right" width="300" src="./assets/padhate-kaise-hain.jpg" alt="clone this repository" />

> Theory part covers topics like data types, operators, control structures, functions, arrays, pointers, strings, file handling, structures, and unions.

This course is designed to help students understand the practical implementations of those thoeritical concepts taught in syllabus.

## How to Submit?

Inside the `[taskname]` folder, there is a `README.md` file that you will write, how the task was implemented. Code in any of `C, Go, Python, Java, C++, C#, JavaScript, PHP` extension file. You can follow this same format to submit your task.

-   Introduction to Question
-   Propose a solution
-   Explanation of the code
-   Output of the code `screenshots`.

When done, there should be two files in the `[taskname]` folder: `README.md` and the code file `[taskname].c` and any required pictures in the `assets` folder.

If some tasks seems challenging, you can use the hint to and research from the available resources below to complete the task.

## Tasks

You're free to write in `C, Go, Python, C++, JavaScript, PHP` as you prefer, once understood the concept, you can implement it in any language you like.

-   [ ] [Sqrt](./sqrt/)
-   [ ] [Cash](./cash/)
-   [ ] [Longer](./longer/)
-   [ ] [Timediff](./timediff/)
-   [ ] [cAPI](./capi/)
-   [ ] [NotError](./noterror/)
-   [ ] [Task 7 TBD]()
-   [ ] [Task 8 TBD]()
-   [ ] [Task 9 TBD]()
-   [ ] [Task 10 TBD]()

### Task 1: Sqrt

A program to calculate the square root of a number without using the sqrt() function. Your program should include the following:

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

### Task 4: Timediff

A program that takes two time inputs (hours, minutes, and seconds) in 24-hour format and calculates the following:

-   The time difference between the two inputs (output the result as hours, minutes, and seconds).
-   Add a specified number of seconds to one of the time inputs and output the resulting time in 24-hour format, ensuring that it wraps correctly (e.g., 23:59:59 + 1 second should give 00:00:00).
-   Ensure that your program handles edge cases like crossing midnight or when the first time is greater than the second time.

_Hint: time.h_

### Task 5: cAPI

A program that implements a simple HTTP server capable of handling basic REST API requests. The server should listen on a specified port and respond to the following endpoints:

-   GET /status – Returns a JSON response indicating the server status (e.g., {"status": "running"}).
-   POST /echo – Accepts a string in the request body and returns the same string in the response (echoes the input).
-   GET /time – Returns the current server time in a simple JSON format (without using `<time.h>`).

_Hint: [<netinet/in.h>](https://man7.org/linux/man-pages/man0/netinet_in.h.0p.html) <unistd.h>_

### Task 6: NotError

Implement a robust error-handling mechanism for a program that performs file operations, memory allocation, and network communications. Your error handler should:

-   Log errors to a file whenever an operation fails, including information about the type of error, where it occurred, and a human-readable message.
-   Return appropriate error codes for different types of errors (e.g., file I/O errors, memory allocation errors, network errors).
-   Provide a function void handle_error(int error_code, const char\* message) to manage all errors. This function should:
-   Print a user-friendly message to the console based on the error code.
-   Log the error details into a file (error_log.txt) in a structured format.
-   Use a global error handling system where error codes are managed centrally, and specific error details (e.g., function name, line number) are passed into the handler.
-   Exit the program gracefully if critical errors (like memory allocation failure) occur, releasing any allocated resources.

## Resources

Watch `Cs50x` lecture on [C](https://www.youtube.com/watch?v=cwtpLIWylAw) and [Memory](https://www.youtube.com/watch?v=F9-yqoS7b8w&t=1s) to understand the basics of C programming.

-   [Documentation](https://devdocs.io/c/)
-   [GNU C Library v2.40](https://sourceware.org/glibc/manual/2.40/html_node/index.html)
-   [cppreference](https://en.cppreference.com/w/)

## Additional Tasks

Extra awesome problem sets and challenges to practice your skills.

-   [Caesar Cipher](https://cs50.harvard.edu/x/2024/psets/2/caesar/)
-   [Substitution](https://cs50.harvard.edu/x/2024/psets/2/substitution/)
-   [Problem Set 4](https://cs50.harvard.edu/x/2024/psets/4/)
