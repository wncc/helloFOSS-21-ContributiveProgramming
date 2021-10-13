# Minimum Stack

The aim of this directory is to create an implementation of a class than can implement the functions of a MinStack: push, pop, top and getMin in ```O(1)``` time.

Your submission must be of the form ```github-username.cpp```, which will import the header file ```MinStack.h```. You have to define the functions declared in the header file in your .cpp file. 

Make sure that your main function handles input-output correctly, and that your implementation gives the correct output on sample input. The input format and problem description is as follows:

## Problem Statement

An empty stack must be initialised for each testcase in your program. Next, your implementation should handle 'q' queries of the following 4 types - push, pop, top and minimum element in the stack.

## Input Format

The first line contains ```t```, the number of testcases. 

For each testcase the first line contains ```q```, the number of queries where  ```1 <= q < 10^5```

The next ```q``` lines will contain queries of the following 3 types:
- ```1 v``` - Push the positive element v at the top of the stack. If stack is full, print ```FULL```.
- ```2``` - Pop the top element of the stack and print it. If stack is empty, print ```EMPTY```.
- ```3``` - Print the top element of the stack. If stack is empty, print ```EMPTY```.
- ```4``` - Print the minimum element in the stack. If stack is empty, print ```EMPTY```.

## Sample Test Case

### Input:

```
1
9
1 3
1 1
1 5
4
2
3
2
2
3
```

### Output:

```
1
5
1
3
EMPTY
```
