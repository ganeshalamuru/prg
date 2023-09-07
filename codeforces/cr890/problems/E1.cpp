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


ll dfs(int node, vector<vector<int>> &edges, vector<int> &vis, ll& ans) {
    vis[node] = 1;
    vector<ll> numnodes;
    for(int v:edges[node]) {
        if (vis[v] != 1)
            numnodes.push_back(dfs(v,edges,vis,ans));
    }
    if (numnodes.size() == 0) {
        return 1;
    }
    ll sum = 0, n = numnodes.size();
    vector<int> dp(10001,0);
    dp[5000] = 1;
    for(int i=0;i<n;i++) {
        sum+=numnodes[i];
        vector<int> dp2(10001,0);
        for(int j=0;j<10001;j++) {
            if (dp[j] == 1) {
                if (j + numnodes[i]<10001)
                    dp2[j+numnodes[i]] = 1;
                if (j-numnodes[i]>=0)
                    dp2[j-numnodes[i]] = 1;
            }
        }
        dp = dp2;
    }
    int minabsdiff = INT_MAX;
    for(int j=0;j<10001;j++)
        if (dp[j] == 1)
            minabsdiff = min(minabsdiff, abs(j-5000));
    ans += ((sum+minabsdiff) / 2) * ((sum - minabsdiff) / 2);
    return sum + 1;
}


void solve(){
	int n;
    cin >> n;
    vector<int>vis(n+1,0);
    vector<vector<int>>edges(n+1);
    for(int u,i=2;i<=n;i++) {
        cin >> u;
        edges[i].push_back(u);
        edges[u].push_back(i);
    }
    ll ans = 0;
    dfs(1, edges, vis, ans);
    cout << ans << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
