You could learn more about the algorithm [here](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).

The algorithm described runs in ```O(N log log N)``` time, Can you do better?

Try implementing the Sieve of Eratosthenes in Asymptotically linear time in ```sieve.cpp```, making use of the directions provided in the file ```sieve.h```, which also contains the declarations of our classes.

After you're done implementing these, you could use that class to solve the following problem : 

It has been known for several centuries now that the excessive use of Fossil Fuels causes numerous problems for the Earth.

What's also known(but not appreciated as much!) are the problems it causes for communities among which these power plants are built.

Ved was very enthusiastic towards helping people from these communities and observed an accidental, yet key feature about these power plants, during his brief stay in the Energy Department: 

There were ```N``` power plants, numbered distinctly from ```1 to N```.

Apparently whoever planned these power plants was well-aware of the problems it may cause for the communities around and added a discrete feature to cluster of such plants, i.e. Two or more power plants do not surround a common community iff the number identifying these plants are pair-wise co-prime to each other.

Now, With this key information can you build a remote control for such power plants, which makes sure that at any point of time, there is at most 1 power plant active around any particular community?

### Input Format

The first line contains a single integer ```T``` denoting the number of test cases.

```T``` test cases follow.

The first line of each Test Case contains an integer ```N```, the number of Power Plants and ```M```, the number of commands the remote control receives.

It is followed by ```M``` lines each of the form :

```+ x```, which means turn on the Power plant numbered ```x```.

``` - x ```, which means turn off the Power Plant numbered ```x```.

We will never ask you to turn off a power plant which isn't already turned on.

### Output Format

For each command, print one of the following, followed by an ```EOL```.

```Success``` : If the particular command lead to a successful turning on/off.

```Conflict``` : If the Power plant can't be turned on, because it surrounds a community with another power plant already turned on.

```AlreadyOn``` : When you try to turn on a Power Plant which is already on.