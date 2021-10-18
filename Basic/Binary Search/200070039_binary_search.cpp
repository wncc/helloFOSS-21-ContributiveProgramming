#include <iostream>

using namespace std;

int bin_min (int l, int u, int n) {
    if (u == l + 1) {
        return l;
    }
    int mid = (l + u) / 2;
    int m = mid * (mid + 1) / 2;
    if (n < m) {
        return bin_min (l, mid, n);
    }
    else {
        return bin_min (mid, u, n);
    }
}

int bin_max (int k, int l, int u, int n) {
    if (u == l + 1) {
        return l;
    }
    int mid = (l + u) / 2;
    int m = k * mid - mid * (mid - 1) / 2;
    if (n > m) {
        return bin_max (k, mid, u, n);
    }
    else {
        return bin_max (k, l, mid, n);
    }
}

int min_num (int n, int k) {
    if (k < 1) {
        return -1;
    }
    if (n < 1) {
        return -1;
    }
    if (n < k + 1) {
        return 1;
    }
    int m = k * (k + 1) / 2;
    if (n > m) {
        return -1;
    }
    if (n == m) {
        return k;
    }
    int x1 = bin_min (1, k, n);
    int x2 = bin_max (k, 1, k, n);
    if (x2 < x1) {
        return x2 + 1;
    }
    else {
        return -1;
    }
}

int main (){
    int t;
    int N[100];
    int K[100];
    cin >> t;
    int i = 0;
    while (i < t) {
        cin >> N[i] >> K[i];
        i = i + 1;
    }
    i = 0;
    while (i < t) {
        cout << min_num (N[i] - 1, K[i] - 1) << "\n";
        i = i + 1;
    }
    return 0;
}
