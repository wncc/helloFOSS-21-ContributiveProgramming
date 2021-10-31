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
  
  ll n,k;
  cin>>n>>k;

  if(k*(k-1)/2+1 <n) cout<<-1;
    else{
        ll start=0,end=k,mid;

        while(start<end){
            mid=start+(end-start)/2;

            ll val=k*(k-1)/2+1-(mid*(mid+1)/2);
            if(val>=n){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        cout<<k-start;
    }


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

