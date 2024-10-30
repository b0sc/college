# DSA

> Theory part covers topics like Introduction to Algorithms, Stack, Queue, Recursion, List, Tree, Sorting, Searching, Hashing and Graph.

> This course is designed to help students understand the practical implementations of those thoeritical concepts taught in syllabus.

## How to Submit?

Inside the `[taskname]` folder, there is a `README.md` file that you will write, how the task was implemented. Code in any of `C, Go, Python, Java, C++, C#, JavaScript, PHP` extension file. You can follow this same format to submit your task.

-   Introduction to Question
-   Propose a solution
-   Explanation of the code
-   Output of the code `screenshots`.

When done, there should be two files in the `[taskname]` folder: `README.md` and the code file `[taskname].c` and any required pictures in the `assets` folder.

## Tasks

You're free to write in `C, Go, Python, C++, JavaScript, PHP` as you prefer, once understood the concept, you can implement it in any language you like.

-   [ ] [SortRace](https://github.com/b0sc/sortRace)
-   [ ] [Tower of Hanoi](./tower_of_hanoi/)
-   [ ] [RunOff](./runoff/)
-   [ ] [Stack](./stack/)
-   [ ] [Queue](./queue/)
-   [ ] [Task 6 TBD]()
-   [ ] [Task 7 TBD]()
-   [ ] [Task 8 TBD]()
-   [ ] [Task 9 TBD]()
-   [ ] [Task 10 TBD]()

### Task 1: SortRace

> SortRace is a program that compares the performance of different sorting algorithms. We've created a seperate [repository](https://github.com/b0sc/sortRace) for this task, where you can contribute to the project.

> You will visualize the performance of different sorting algorithms like Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort, Heap Sort etc.

### Task 2: Tower of Hanoi

> Tower of Hanoi is a mathematical puzzle that consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with all the disks stacked in ascending order of size on one rod, with the smallest disk at the top. The objective of the puzzle is to move the entire stack of disks to another rod, following these rules:

-   Only one disk can be moved at a time.
-   Each move consists of taking the top disk from one of the stacks and placing it on another rod.
-   No disk may be placed on top of a smaller disk.
    Your task is to implement the Tower of Hanoi solution recursively in C. Specifically:

Write a recursive function `void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)` that moves `n` disks from the `from_rod` to the `to_rod` using the `aux_rod` as auxiliary.

Print out the sequence of moves as Move disk X from rod A to rod B, where X is the disk number, A is the source rod, and B is the destination rod.
Test your program with different values of n (the number of disks), ensuring that the output is correct for 1, 2, 3, 4, and more disks.

For `n=3`, the output should be:

```bash
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C
```

### Task 3: RunOff

Implement a runoff election program where voters rank candidates in order of preference. Your program should simulate multiple rounds of runoff voting until a candidate has more than half of the votes or all remaining candidates are tied. Specifically, your program must:

-   Record each voter’s preferences. Allow voters to rank all candidates in order of preference.
-   Eliminate the last-place candidate in each round of voting.
-   Redistribute votes for eliminated candidates based on each voter's next highest-ranked preference.
-   Check for a majority after each round (i.e., if any candidate has more than half of the votes, they win).
-   Handle ties: If all remaining candidates are tied, the election should end with no winner.

### Task 4: Stack

The task is to implement basic stack operations in and create algorithms that convert an **infix expression** to **postfix** and **prefix** expressions. This exercise will help you understand stack data structures and their practical applications in expression evaluation and conversion.

More info on: [Stack](./stack/question.md)


### Task 5: Queue

The task is to implement the basic queue operations (Enqueue and Dequeue) and to explore different types of queues, including **Linear Queue**, **Circular Queue**, and **Priority Queue**. This exercise will help you understand the queue data structure, its variations, and practical applications in managing and prioritizing data.

More info on: [Queue](./queue/question.md)

_Hint:Greedy Elimination, Sorting, Linear Search._ Check [here](https://cs50.harvard.edu/x/2024/psets/3/runoff/) for more details.

## Resources

Watch `Cs50x` lecture on [Algorithms](https://www.youtube.com/watch?v=jZzyERW7h1A) and [Data Structures](https://www.youtube.com/watch?v=0euvEdPwQnQ) to understand the basics of DSA course.

-   [Tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/index.htm)
-   [GeeksforGeeks](https://www.geeksforgeeks.org/learn-data-structures-and-algorithms-dsa-tutorial/?ref=shm)

## Additional Tasks

Extra awesome problem sets and challenges to practice your skills.

-   [Plurality](https://cs50.harvard.edu/x/2024/psets/3/plurality/)
-   [Inheritance](https://cs50.harvard.edu/x/2024/psets/5/inheritance/)
