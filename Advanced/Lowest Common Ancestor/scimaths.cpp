#include <bits/stdc++.h>
using namespace std;
#define int long long
int P = 1000000007;
int P2 = 998244353;
#define F first
#define S second
#define pb push_back
#define mp make_pair

vector<int> g[200010];
int k = 0;
int par[200010][20];
vector<int> in(200010);
vector<int> out(200010);

void dfs (int nn, int pp) {
    par[nn][0] = pp;
    k++;
    in[nn] = k;
    for (auto v:g[nn]) {
        if (v==pp) {continue;}
        dfs(v,nn);
    }
    k++;
    out[nn] = k;
}

void set_par(int n) {
    for (int i=1; i<=19; ++i) {
        for (int j=1; j<=n; ++j) {
            if (par[j][i-1]==-1) {par[j][i]=1;}
            else {par[j][i]=par[par[j][i-1]][i-1];}
        }
    }
}

int lca(int x, int y) {
    if (in[x]<=in[y] && out[y]<=out[x]) {return x;}
    if (in[x]>=in[y] && out[y]>=out[x]) {return y;}
    int val = 19;
    int u = x;
    while(val>=0) {
        int z = par[u][val];
        if (z == -1 || (in[z]<=in[y] && out[y]<=out[z])) {val--;}
        else {u = par[u][val]; val--;}
    }
    return par[u][0];
}

void solve () {
	int n, r, x, y; cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> x >> y; g[x].pb(y); g[y].pb(x);
    }
    n++;
    dfs(1,-1);
    set_par(n);
    int q; cin >> q;
    for (int i=0; i<q; ++i) {
        cin >> r >> x >> y;
        int a = lca(x,y);
        int b = lca(r,x);
        int c = lca(r,y);
        if (lca(a,b)==a && lca(c,b)==c) {cout << b << '\n';}
        else if (lca(a,b)==b && lca(c,a)==c) {cout << a << '\n';}
        else if (lca(a,c)==a && lca(c,b)==b) {cout << c << '\n';}
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    // freopen("output.txt", "w", stdout);
	#endif
    int t = 1;
    // cin >> t;
    for (int _t=0; _t<t;++_t) {
        // cout << "Case #" << _t+1 << ": ";
        solve();
    }
}