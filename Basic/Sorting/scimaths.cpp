#include <bits/stdc++.h>
using namespace std;
#define int long long
int P = 1000000007;
int P2 = 998244353;
#define F first
#define S second
#define pb push_back
#define mp make_pair

void solve () {
	int n; cin >> n;
    string s[n];
    int arr[n];
    for (int i=0; i<n; ++i) {
        cin >> s[i];
        if (s[i]=="XS") {arr[i]=1;}
        if (s[i]=="S") {arr[i]=2;}
        if (s[i]=="M") {arr[i]=3;}
        if (s[i]=="L") {arr[i]=4;}
        if (s[i]=="XL") {arr[i]=5;}
        if (s[i]=="XXL") {arr[i]=6;}
        if (s[i]=="XXXL") {arr[i]=7;}
    }
    vector<int> v(8);
    int inv = 0;
    for (int i=0; i<n; ++i) {
        v[arr[i]]++;
        for (int j=arr[i]+1; j<8; j++) {
            inv += v[j];
        }
    }
    cout << inv << '\n';
    sort(arr,arr+n);
    for (int i=0; i<n; ++i) {
        switch(arr[i]) {
            case 1: cout << "XS "; break;
            case 2: cout << "S "; break;
            case 3: cout << "M "; break;
            case 4: cout << "L "; break;
            case 5: cout << "XL "; break;
            case 6: cout << "XXL "; break;
            case 7: cout << "XXXL "; break;
        }
    }
    cout << '\n';
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