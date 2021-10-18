#include <bits/stdc++.h>
using namespace std;
#define int long long
int P = 1000000007;
int P2 = 998244353;
#define F first
#define S second
#define pb push_back
#define mp make_pair

bool check (int n, int k, int a) {
    return 1+(k-1)*k/2-(k-a-1)*(k-a)/2 >= n;
}

void solve () {
	int n, k;
    cin >> n >> k;
    if (1+k*(k-1)/2 < n) {cout << "-1\n"; return;}
    int l=1, r=k-1, ans=-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (check(n,k,mid)) {ans=mid; r=mid-1;}
        else {l=mid+1;}
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    // freopen("output.txt", "w", stdout);
	#endif
    int t = 1;
    cin >> t;
    for (int _t=0; _t<t;++_t) {
        // cout << "Case #" << _t+1 << ": ";
        solve();
    }
}