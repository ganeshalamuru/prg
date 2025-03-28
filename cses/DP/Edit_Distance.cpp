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
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++)
        dp[i][0]=i;
    for(int j=1;j<=m;j++)
        dp[0][j]=j;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if (s1[i-1]==s2[j-1]) {
                // matching last char
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            } else {
                // replace last char
                if (dp[i-1][j-1]!=INT_MAX)
                    dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);
                // delete last char    
                if (dp[i-1][j]!=INT_MAX)
                    dp[i][j]= min(dp[i][j], 1+dp[i-1][j]);
                // insert last char    
                if (dp[i][j-1]!=INT_MAX)
                    dp[i][j]= min(dp[i][j], 1+dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
