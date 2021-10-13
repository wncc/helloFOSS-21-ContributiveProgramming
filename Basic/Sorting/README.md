# Sorting

Goodwill India is working towards poverty eradication and improving the environment by collecting E-waste, used clothes and other such used items. Every week, this social organisation collects hundreds of used clothes from all over the city, which are then distributed to the needy and underprivileged people after due processing.

Jash has been given the task to organise the donated clothes according to their size, so that they can be processed further accordingly. This task needs to be done as quickly as possible, and he wishes to figure out how long will it take him to sort the clothes. Quantitavely, the time required to do this task is proportional to the number of inversions in the pile of clothes.

Help Jash figure out the time it would take him to sort the clothes in an increasing order of size, and how the pile of clothes should look after organising.

## Input Format

The first line of the input contains ```t```, the number of test cases. Then ```t``` test cases follow.

The first line of each test case contains ```n```, the number of clothes. The next line contains ```n``` space separated strings, the sizes of the clothes in the pile. The sizes are as follows : ```XS, S, M, L, XL, XXL, XXXL```.

## Output Format

For each test case, first print the total number of inversions. An inversion a pair of clothes present as index i,j such that i<j and size(j) > size(i).

On the next line, print the sizes of the clothes in increasing order.

## Constraints

1 < ```t``` < 100

1 < ```n``` < 10^5

It is guranteed that the sum of ```n``` over all cases does not exceed 2x10^6.


## Sample Test Case

### Input

```
2
5
S XS L S XXXL
2
S M
```

### Output
```
2
XS S S L XXXL 
0
S M 
```

Submit a single file ```github-username.cpp``` that takes input from ```input.txt``` and prints output to stdout.