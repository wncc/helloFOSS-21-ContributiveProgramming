#include<bits/stdc++.h>
#define int long long
using namespace std;
#define INF 1000000007
#define N 100000

void solve () {
	int t,n;
	cin >> t >> n;

	vector<int>x(N),y(N);

	for(auto i=0;i<n;i++)
		cin >> x[i];

	for(auto i=0;i<n;i++)
		cin >> y[i];

	int dp[n][t+1];

	for(auto i=0;i<n;i++)
		for(auto j=0;j<=t;j++)
			dp[i][j]=0;

	for(auto i=0;i<=t;i++)
		if(x[0]<=i)
			dp[0][i]=y[0];

	for(auto i=1;i<n;i++)
		for(auto j=1;j<=t;j++)
		{
			int temp1=0;
			int temp2=0;
			if(x[i]<=j)
				temp1=y[i]+dp[i-1][j-x[i]];
			temp2=dp[i-1][j];
			dp[i][j]=max(temp1,temp2);
		}
	cout << dp[n-1][t] << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	
	while(t--){
		//cout << "Case " << temp-t << ":\n"; 
		solve();
	}
}

