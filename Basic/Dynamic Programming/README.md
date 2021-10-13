# Dynamic Programming

There is a school for underprivileged children near IIT Bombay. But the school has had trouble finding a Math teacher for the students for a few months now. Shubh decided to step up and perform a good social deed by offering to teach the kids. 

The students' exams are coming up and there is not enough time to teach them the entire syllabus. Can you help Shubh decide which chapters to teach the children to maximise their chances of acing their exams?  

## Problem Statement

For each testcase, there will be maximum allowed time ```T``` and ```n``` possible chapters. The ```i th``` chapter takes a specific amount of time ```x[i]``` to teach and has a fixed weightage ```y[i]``` in terms of marks.        

You need to find the maximum amount of weightage in terms of marks which Shubh can cover within the given allowed time. Shubh can decide either to teach or not teach a specific chapter. Note that it is not possible to teach a fraction of a chapter as that will not help the kids.  

## Input Format

The first line contains ```t```, the number of testcases. 

The first line for each testcase contains ```T n```, the maximum allowed time and the number of chapters.

The next 2 lines contains ```n``` space seperated integers. The first line contains the time taken to complete each chapter ```x[i]```  and the second line contains the weightage each chapter ```y[i]``` from 1 to n. 

## Output Format

Print the maximum weightage(marks) which Shubh can cover within the given time.

## Constraints
1 <= ```n``` <= 100     
1 <= ```T``` <= 10^5   
1 <= ```x[i]``` <= ```T```   
1 <= ```y[i]``` <= 10^9   

## Sample Test Case

### Input:

```
2
8 3
6 4 3
50 40 15
10 5
5 3 4 4 2 
6 3 5 6 1
```

### Output:

```
55
12
```
