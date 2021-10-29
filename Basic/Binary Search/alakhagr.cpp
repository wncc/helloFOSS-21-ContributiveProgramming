#include<bits/stdc++.h>

using namespace std;

void myfunc(int n, int k, long int ans[], long int i){
    int  t=1, temp=0;

    if(n<=k) ans[i]=1;
    else{
        while (true){
            t += (min(n-t+1, k)-1);
            k--;    
            temp++;
            if(t==n) {
                ans[i] = temp;
                break;
            }
            if (t>n || k<2){ 
                ans[i] = -1;
                break;
                }
            }
        }
}

int main(){
    int tc, tc1;
    cin >> tc;
    tc1 = tc;
    long int ans[100], i=0; //array to store answers for final cout
    while (tc>0){
        int n, k;
        cin >> n >> k;
        myfunc(n, k, ans, i);
        tc--;
        i++;
        }
    for(int i=0; i<tc1; i++) cout << ans[i] << endl;
    return 0;
}