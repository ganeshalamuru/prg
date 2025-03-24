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
	int n;
    cin >> n;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
        cin >> grid[i];
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++) {
        if (grid[i][0]!='*')
            dp[i][0]=1;
        else
            break;
    }
    for(int j=0;j<n;j++) {
        if (grid[0][j]!='*')
            dp[0][j]=1;
        else
            break;
    }
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            if (grid[i][j]=='*')
                continue;
            if (grid[i-1][j]!='*')
                dp[i][j]=(dp[i][j] + dp[i-1][j])%mod;
            if (grid[i][j-1]!='*')
                dp[i][j]=(dp[i][j] + dp[i][j-1])%mod;
        }
    }
    cout << dp[n-1][n-1] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
