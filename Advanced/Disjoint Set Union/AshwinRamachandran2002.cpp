#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <numeric>     
#include <algorithm>   
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define ll              int64_t
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<ll>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define fo(i,a,b)       for(ll i=a;i<b;i++)
 
#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()
#define MAXN            100005
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class Tree{

public:
    priority_queue< tuple<ll, ll, ll> > graph;
    ll v;
    ll* link;
    ll* size;
    ll* windmill;

    Tree(int v,ll* weight,ll num_cables){
        this->v=v;
        link= (ll*)malloc(sizeof(ll)*(v+1));
        size= (ll*)malloc(sizeof(ll)*(v+1));
        windmill =(ll*)malloc(sizeof(ll)*(v+1));
        fo(i,1,v+1) {size[i]=1;link[i]=i;windmill[i]=weight[i];}
        //graph = new priority_queue< tuple<ll,ll, ll> >(num_cables);
    }

    void add(ll i,ll j,ll w){
        graph.push({-w,i,j});
    }

    ll find(ll x){
        while(x!=link[x]){
            x=link[x];

        }
        return x;
    }

    bool same(ll a,ll b){
        return find(a)==find(b);
    }

    ll unite(ll a,ll b){
        a=find(a);
        b=find(b);

        if(size[a]<size[b]) swap(a,b);

        size[a]+=size[b];
        ll c=find(b);
        ll d=find(a);
        link[b]=a;
        ll temp=windmill[a];
        windmill[a]=min(windmill[d],windmill[c]);
        return windmill[a]-temp;
    }

    ll implement(){
         ll totalcost=0;
        while(!graph.empty()){
            ll a,b,w;
            tie(w,a,b)=graph.top();w=-w;

            if(!same(a,b)){
                if((windmill[find(a)]+windmill[find(b)])
                    >(w+min(windmill[find(a)],windmill[find(b)]))){
                    totalcost+=w;
                     unite(a,b);
                }
            } 
            graph.pop();
        }
        set<ll> s;

        fo(i,1,v+1){
            s.insert(find(i));
        }
        for(auto e:s){
            totalcost+=windmill[e];
        }
        return totalcost;


    }
};


void solve(){
    ll vil,cab,fund;
    cin>>vil>>cab>>fund;
    ll weight[vil+1];
    fo(i,1,vil+1) cin>>weight[i];

    Tree spanning=Tree(vil,weight,cab);
    

    fo(i,0,cab){
        ll a,b,c;
        cin>>a>>b>>c;
        spanning.add(a,b,c);
    }

    
    ll ans=spanning.implement()-fund;
    if(ans<0) cout<<0;
    else cout<<ans;
   
}
 
 
int32_t main()
{
   
    c_p_c();
 
    ll t=1;
    cin>>t;
    while(t-->0){
        
        solve();
        cout<<"\n";
    }
 
}

