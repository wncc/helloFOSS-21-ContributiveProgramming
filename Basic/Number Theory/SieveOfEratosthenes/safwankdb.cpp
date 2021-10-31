#include <bits/stdc++.h>

using namespace std;
static const int N = 1024;
static int counts[N+1] = {};

template<int n, int m>
struct checkPrime {
    static const bool isPrime = (n % m != 0) && checkPrime<n, m-1>::isPrime;
};

template<int n>
struct checkPrime<n, 1> {
    static const bool isPrime = true;
};

template <int m>
void Init() {
    Init<m-1>();
    counts[m] = counts[m-1] + checkPrime<m, m-1>::isPrime;
}

template<>
void Init<2>() {
    counts[2] = 1;
    counts[1] = 0;
    counts[0] = 0;
}


int main() {
    Init<N>();
    for (int i = 1; i <= N; i++)
        if (counts[i] > counts[i-1]) cout << i << ' ';
    cout << endl;
}
