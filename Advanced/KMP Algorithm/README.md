# Knuth-Morris-Pratt Algorithm

Shubh, once an established software engineer and an IITB graduate, has decided to pursue his true passion - writing storybooks for chidren! 

However, the night before his first pitch to the publishers, his PC malfunctioned and all his drafts got corrupted. On inspection, he found that the last word on his clipboard had been inserted at random places all over his draft. 

He realised he could still save his drafts if he could somehow get all the locations where the word had been inserted. This task reminded him of the KMP algorithm for string matching. However, it's been years since he attended his DSA lectures and the details of the algorithm are a bit fuzzy to him. 

He entrusts you, his best friend, with the task of finding all such locations. In particular, he wants you to give him the list of the indices(for every chapter) of the first character of the word at every place it was inserted.

Time is of essence to him and n^2 algorithms will certainly not work. Help Shubh recover his drafts before its too late!

## Input Format

The first line of the input contains ```n```, the number of chapters in Shubh's book and the word to be searched ```w```. Then ```n``` lines follow. Each line contains the content of a chapter, compressed by removing the whitespaces.

For every chapter, output the number of occurences of the word followed by the space separated list of indices as mentioned in the problem statement.

## Constraints
1 < ```n``` < 100

1 < ```|w|``` < 10000

It is guaranteed that the total number of characters over all the chapters combined will not exceed 200000.

## Sample Test Case

### Input

```
2 foo
foobarfoofoobar
xyzfoooofooffoofoo
```

### Output

```
3
0 6 9
4
3 8 12 15
```

Submit a single file ```github_username.cpp``` that takes in input from ```input.txt``` and prints output to stdout.