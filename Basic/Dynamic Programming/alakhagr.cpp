#include<bits/stdc++.h>

using namespace std;

int maxweightage(int T, int x[], int y[], int n){
    if(n==0 || T==0) return 0;

    if(x[n-1]>T) return maxweightage(T, x, y, n-1);

    return(max((y[n-1]+maxweightage(T-x[n-1], x, y, n-1)), maxweightage(T, x, y, n-1)));
}

int main(){
    int tc, tc1;
    cin >> tc;
    tc1 = tc;
    int ans[100], i=0;
    while(tc>0){
        int T, n, x[100], y[100];
        cin >> T >> n;
        for(int i=0; i<n; i++) cin >> x[i];
        for(int i=0; i<n; i++) cin >> y[i];
        ans[i]=maxweightage(T, x, y, n);
        i++;
        tc--;
    } 

    for(int j=0; j<tc1; j++) cout << ans[j] << endl;

    return 0;
}