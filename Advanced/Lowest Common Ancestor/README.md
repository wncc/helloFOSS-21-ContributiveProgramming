# Lowest Common Ancestor - LCA

Subarno is going to start an NGO for teaching underprevileged children. As he is busy in trying to achieve his goal, he needs help in organising the structure of employees in his company. 

Given any 2 employees, you have to find the lowest common senior(ancestor) of the 2 employes for him. 


## Input Format

The first line of the input contains an integer ```n```. The next ```n``` lines contains 2 integers ```x``` and ```y``` which represents an edge between these 2 vertices. Note that all vertices will have unique values. 

The next line contains the number of queries ```q```. Each of the next ```q``` lines contains 3 integers ```r```, ```x``` and ```y```. 

## Output Format

For each of the ```q``` queries print the LCA of the vertices ```x``` and ```y``` if the root was at vertex ```r```. 

## Relevant Constraints

1<= ```n,q``` <= 2*10^5

## Sample Test Case

### Input

```
3
2 1
2 3
3 4
3
2 1 3
2 4 3
1 2 4 
```

### Output

```
2
3
2
```

## Submission Format

You have to submit a single file ```github_username.cpp``` which gives the output described above depending on sample input.
