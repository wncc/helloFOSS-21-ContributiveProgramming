You may learn about the [Extended Euclid's Algorithm](https://brilliant.org/wiki/extended-euclidean-algorithm/#extended-euclidean-algorithm).

It's just a more powerful version of the Euclid's Algorithm you studied about in Std.10th, which allows you to calculate, besides the ```GCD``` of two numbers ```a``` and ```b```, a duplet of numbers ```(x,y)```, such that : ```ax + by = gcd(a,b)```.

This brings with itself a lot of applications, the simplest one being now you can calculate the Multiplicative inverse of any number modulo ```m```, whenever the number is co-prime with ```m```.

Implement the functionality described above in ```euclid.cpp```, using the guidelines and declarations provided in ```euclid.h```.

Then, use this implementation(and also the [Chinese Remainder Theorem](https://en.wikipedia.org/wiki/Chinese_remainder_theorem)) to solve Shreedhar's Problem:

Shreedhar has decided to put an end to water-bourne diseases using a special device of his own making which he calls ```the Cleanser```. He plans to install this device at all potholes in the city.

He recently heard of an initiative of the Government to collect information about places of Water Stagnation and decided to get this data for himself, so that he could end the problem without having to rely on the government.

The Officer he approached for the same got tempted for some bribes in return of the information, but instead of asking for it straight off, he gave Shreedhar a puzzle, thinking he won't be able to solve it by himself.

The Officer tells Shreedhar that all potholes are described by numbers, such that each and every one of them is equal to ```x mod y```, for two integers ```x``` and ```y``` with ```x < y``` He picks up any of these values (say ```z```), and gives Shreedhar the duplet of numbers ```(a,b), a<=b``` such that ```z = a (mod b)```.

He further guarantees that these ```b```(s)  would be relatively prime to each other and product of all ```b```(s) would give him ```y```.

Help Shreedhar calculate ```x```. 

### Input Format

The input starts with a number ```N```, the number of duplets, the Officer would give Shreedhar.

Each of the following lines have two integers ```a``` and ```b```, the duplets as descried above.

### Output Format

For each test case, output ```x```. 
