# DSU and Minimum Spanning Tree

```BLADES``` is an NGO with the aim of making every Indian village energy-independent by 2026. For this purpose, it has planned to build windmills at strategic places so that the electricity generated can be used to power the houses of every village.

The NGO currently has a fund of rupees ```M```. You being their financial analyst, have been given the task to calculate if the current funds are sufficient for this purpose, or if more funds are required. You have the data for the amount required to build a windmill in a village i -> w[i] and the possible electric cables that can be laid, with the cost for each.

## Input Format

The first line of the input contains ```t```, the number of testcases. Then ```t``` test-cases follow.

The first line of each test case contains ```n```, the number of villages, ```m``` the number of cables that can be laid and ```M```, the funds currently available.

The next line contains the space separated list ```w``` where w[i] represents the cost of building a windmill at village i (1-indexed). Then ```m``` lines follow :

Each line contains ```a b c```, which gives the description of the electric cable that can be laid between village ```a``` and ```b``` and the cost of installation is ```c```

## Output Format

Print the minimum additional funds required by the NGO to achieve its goals. If the funds are already sufficient, print ```0```

## Relevant Constraints

1 < ```t``` < 20

0 < ```n``` < 10000

0 <= ```m``` < 10000

0 <= ```w[i]``` < 10000

It is guranteed that the sum of ```m``` over all cases does not exceed 2x10^5 (obviously), and at max 1 electric cable can be laid between 2 villages.

## Sample Test Case

### Input

```
2
3 2 2
1 2 2
1 2 1
2 3 1
1 0 5
567
```

### Output

```
1
562
```

Submit a single file ```github-username.cpp```, that takes input from ```input.txt``` and prints output to stdout.
