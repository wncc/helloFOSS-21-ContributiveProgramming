#include <bits/stdc++.h>

using namespace std;

class Sieve{
    //Declare any variables you may need!


    
    public:
        Sieve(int N);   //The Constructor which takes the number N : The upper bound on primes to be found!
        void run();     //Run the sieve's algorithm to get the prime numbers
        vector<int> getPrimeFactors(int k);  // Get all the prime factors of k (k<=N) as a vector in O(log N) time

};