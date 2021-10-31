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
    ll n;cin>>n;
    ll count[7];
    ll c[n];
    fo(i,0,7) count[i]=0;
    ll ans=0;
    fo(i,0,n){
        string a;cin>>a;
        int term;
        if(a=="XS"){
           count[0]++;
           term=0;
        }
        else if(a=="S"){
            count[1]++;
            term=1;
        }
        else if(a=="M"){
            count[2]++;
            term=2;
        }
        else if(a=="L"){
            count[3]++;term=3;
        }
        else if(a=="XL"){
            count[4]++;term=4;
        }
        else if(a=="XXL"){
            count[5]++;term=5;
        }
        else if(a=="XXXL"){
            count[6]++;term=6;
        }
        c[i]=term;
        fo(j,term+1,7){
            ans+=count[j];
        }
    }

    cout<<ans<<endl;

    sort(c,c+n);

    fo(i,0,n){
        if(c[i]==0){
           cout<<"XS ";
        }
        else if(c[i]==1){
           cout<<"S ";
        }
        else if(c[i]==2){
           cout<<"M ";
        }
        else if(c[i]==3){
           cout<<"L ";
        }
        else if(c[i]==4){
           cout<<"XL ";
        }
        else if(c[i]==5){
           cout<<"XXL ";
        }
        else if(c[i]==6){
           cout<<"XXXL ";
        }
        
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

