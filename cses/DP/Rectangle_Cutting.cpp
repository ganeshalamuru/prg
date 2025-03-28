#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}




void solve() {
	int a,b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,INT_MAX));
    for(int i=1;i<=min(a,b);i++)
        dp[i][i]=0;
    for(int i=2;i<=a;i++)
        dp[i][1]=i-1;
    for(int j=2;j<=b;j++)
        dp[1][j]=j-1;
    
    for(int i=2;i<=a;i++) {
        for(int j=2;j<=b;j++) {
            if (i==j)
                continue;
            for(int z=1;z<i;z++) {
                dp[i][j] = min(dp[i][j], 1 + dp[z][j]+dp[i-z][j]);
            }
            for(int z=1;z<j;z++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][z]+dp[i][j-z]);
            }
        }
    }
    cout << dp[a][b] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
