#include <iostream>

using namespace std;

int min_num (int n, int k) {
    if (k < 2) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return -1;
    }
    if (n < k + 1) {
        return 1;
    }
    int m;
    m = k * (k + 1) / 2;
    if (n > m) {
        return -1;
    }
    int min = k;
    int num = k;
    int i = k;
    while (i > 1) {
        num = 1 + min_num (n - i, i - 1);
        if (num > 0 && num < min) {
            min = num;
        }
        i = i - 1;
    }
    if (min < k){
        return min;
    }
    else{
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
        cout << min_num (N[i], K[i]) << "\n";
        i = i + 1;
    }
    return 0;
}
