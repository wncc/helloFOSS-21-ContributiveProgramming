# Binary Search

Scarcity of clean drinking water is a major issue prevalent in many villages in India. India, an agricultural country, produces a huge quantity of food to feed its population. However, agriculture requires a lot of water, and the traditional methods of irrigation wastes a lot of water due to evaporation, water conveyance, drainage, percolation, and the overuse of groundwater.

Thus the Municipal Corporation of Paanipat has decided to use drip irrigation for irrigating crops wherever possible in the district. With this method of irrigation, water and nutrients are delivered directly to the plants' roots, which leads to huge water savings as there is no loss due to evaporation or run-off.

## Problem Statement

You have been given the task to create the pipeline network for drip irrigation. The pipeline initially consists of a single main water pipeline, and this water has to be distributed among smaller pipes so that the water can be used for drip irrigation.

For this task, you have a variety of splitters that can split the water from the input pipe to multiple output pipes. In particular, you have a splitter of each kind : with 2, 3, ..., k outputs. At most any 1 splitter can be connected to a water pipe.

You need to find the minimum number of splitters required so that the main water supply can be split into ```n``` water pipes.

## Input Format

The first line contains ```t```, the number of testcases. 

The only line for each test case contains the integers ```n```, the desired number of output pipes and ```k``` as given in the problem statement.

## Output Format

Print the minimum number of splitters required to accomplish the task. If it is impossible to do so, print ```-1```.

## Constraints

1 < ```t``` < 100

1 < ```n``` < 10^18

1 < ```k``` < 10^9

## Sample Test Case

### Input:

```
3
4 3
5 5 
8 4
```

### Output:

```
2
1
-1
```
