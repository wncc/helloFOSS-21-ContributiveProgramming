# Sweep Line Algorithms

The Volunteers from NSS, IIT-B had recently decided to put a stop to Child Labour in Mumbai's Suburban areas.

They realized that this illicit activity was largely controlled by Cartels which organize them and supervise their work at Construction Sites. It was soon found out that these construction sites were present on various streets many of which intersected.

Subarno was made in-charge of this enterprise to free these children. Being quite the strategist(besides being a Master at CP!), he observed that children on Intersecting streets were supervised by the same person, so in order to trick this person, he decided to rescue children a street at a time, such that on any day, he rescued children from a particular set of streets none of which were intersecting, so that even if the children from one of the streets disappear the supervisor could be content supervising children on the other street.

Subarno wonders how many children would he be able to rescue?

### Input Format

The first line contains a single integer ```N```, denoting the number of streets.
The next ```N``` lines would each be describing one of these streets by a ```4-tuple``` of integers : ```x_1, y_1, x_2, y_2```, where the first two ascertain the starting point of the street, whereas the latter two ascertain the end point.

### Output Format

Output a single integer for every test-case, denoting the maximum number of children Subarno could rescue.

### Input Constraints

While contriving your program you may assume : ``` N <= 10^5``` and ```Number of Street Intersections <= 10^5```.

You may learn more about solving the problem using Line Sweep Methods from the subsection on Line Sweep Method and Segment Intersection Problem in Plane Sweep Technique and Applications section from [this course](https://nptel.ac.in/courses/106/102/106102011/).

You need to write your code in ```sweep.cpp``` and push it to your cloned repo alongwith your own ```sweep.h```, and then create a Pull Request in order to contribute!
