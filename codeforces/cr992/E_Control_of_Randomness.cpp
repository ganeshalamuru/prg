#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 998244353, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

void dfs(int u, int p, int d,int n, vector<vector<int>>&adj, vector<vector<vector<int>>>&dp, vector<int> &depth) {
    dp[u][0][1]=1+dp[p][0][0];
    dp[u][0][0]=2*(adj[u].size()-1)+1+dp[p][0][1];
    for(int c=1;c<=n;c++) {
        dp[u][c][1]=1+dp[p][c][0];
        dp[u][c][0]=min(1+dp[p][c-1][1], 2*(int)(adj[u].size()-1)+1+dp[p][c][1]);
    }
    depth[u]=d;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs(v,u,d+1,n,adj,dp,depth);
    }
}

void solve() {
	int n,q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1,vector<int>(2,0)));
    vector<int> depth(n,0);
    for(int i=0;i<=n;i++)
        dp[0][i][0]=dp[0][i][1]=0;
    for(int &v:adj[0])
        dfs(v,0,1,n,adj,dp,depth);
    while(q--) {
        int v,p;
        cin >> v >> p;
        v--;
        if (p>=depth[v]/2) {
            cout << depth[v] << "\n";
        } else {
            cout << dp[v][p][1] << "\n";
        }
    }
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
