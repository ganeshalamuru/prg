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



void dfs(int u, int p, vector<vector<int>>&adj, vector<int>&dp) {
    int maxdepth = -1;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs(v, u, adj, dp);
        maxdepth=max(maxdepth, dp[v]);
    }
    dp[u] = maxdepth+1;
}

int dfs2(int u, int p, int a, vector<vector<int>>&adj, vector<int> &path) {
    if (u==a)
        return 1;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        path.push_back(v);
        if (dfs2(v,u,a,adj,path)==1)
            return 1;
        path.pop_back();
    }
    return 0;
}
void solve() {
	int n,a,b;
    cin >> n;
    cin >> a >> b;
    a--,b--;
    vector<vector<int>> adj(n);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dp(n,INT_MIN),apath{b};
    dfs(b,-1,adj,dp);
    dfs2(b,-1,a,adj,apath);
    int ans = INT_MAX;
    int p = -1,psz = apath.size();
    for(int i=0;i<psz;i++) {
        int maxex = INT_MIN;
        for(int &v:adj[apath[i]]) {
            if (v==p || (i+1<apath.size() && v==apath[i+1]))
                continue;
            maxex=max(maxex, dp[v]+1);
        }
        if (maxex==INT_MIN)
            maxex=0;
        if (i<=psz/2) {
            ans = min(ans, 2*(n-1)+i-maxex);
        } else {
            ans = min(ans, 2*(n-1)+(psz/2)-(i-psz/2)-maxex);
        }
        p=apath[i];
    }
    cout << ans <<"\n";
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
