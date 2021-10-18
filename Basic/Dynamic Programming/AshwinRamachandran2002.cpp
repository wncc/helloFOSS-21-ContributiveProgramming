#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
using namespace __gnu_pbds;
using namespace std;
#define fo(i,a,b)       for(ll i=a;i<b;i++)
#define ll long long int
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve(){
    ll T,n;
    cin>>T>>n;
    ll time[n];
    ll weight[n];

    fo(i,0,n) cin>>time[i];
    fo(i,0,n) cin>>weight[i];

    ll dp[T];
    fo(i,0,T){
        dp[i]=0;
    }

    fo(i,0,n){
        fo(j,0,T){

            if(time[i]<=j){
                dp[j]=max(dp[j],dp[j-time[i]]+weight[i]);
            }
        }
    }
 
    cout<< dp[T-1]; 


}

 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    c_p_c();
 
    ll t=1;
    cin>>t;
    while(t-->0){
        solve();
        cout<<"\n";
    }
 
}

