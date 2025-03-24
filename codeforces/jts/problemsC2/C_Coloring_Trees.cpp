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

	int n,m,k;
    cin >> n >> m >> k;
    vector<int> color(n);
    for(int &c:color)
        cin >> c;
    vector<vector<int>> cost(n,vector<int>(m+1));
    for(int i=0;i<n;i++)
        for(int j=1;j<=m;j++)
            cin >> cost[i][j];
    
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1,vector<ll>(m+1,LLONG_MAX)));
    for(int z=1;z<=m;z++)
        dp[0][0][z] = dp[0][1][z] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k && j<=i;j++) {
            if (color[i-1] != 0) {
                dp[i][j][color[i-1]] = min(dp[i][j][color[i-1]], dp[i-1][j][color[i-1]]);
                for(int z=1;z<=m;z++) {
                    if (color[i-1]==z)
                       continue;
                    dp[i][j][color[i-1]] = min(dp[i][j][color[i-1]], dp[i-1][j-1][z]);
                }
                continue;
            }
            vector<ll> pref(m+2, LLONG_MAX), suf(m+2, LLONG_MAX);
            for(int z=1;z<=m;z++)
                pref[z] = min(pref[z-1], dp[i-1][j-1][z]);
            for(int z=m;z>=1;z--)
                suf[z] = min(suf[z+1], dp[i-1][j-1][z]);
            for(int z=1;z<=m;z++) {
                if (dp[i-1][j][z] != LLONG_MAX)
                    dp[i][j][z] = min(dp[i][j][z], dp[i-1][j][z] + cost[i-1][z]);
                ll diffcost = min(pref[z-1],suf[z+1]);
                if (diffcost != LLONG_MAX)
                    dp[i][j][z] = min(dp[i][j][z], diffcost + cost[i-1][z]);
            }
        }
    }
    ll ans = LLONG_MAX;
    for(int z=1;z<=m;z++)
        ans = min(ans, dp[n][k][z]);
    if (ans == LLONG_MAX) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}