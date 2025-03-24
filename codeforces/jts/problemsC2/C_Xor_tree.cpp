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



void dfs(int u, vector<vector<int>>&adj, vector<int>&vis, vector<int> &value, vector<int>&goal, int curDepth,
        vector<int> delta, vector<int> &ans) {
    vis[u] = 1;
    int nodeVal = value[u]^delta[curDepth%2];
    if (nodeVal!=goal[u])
        ans.push_back(u);
    for(int &v:adj[u]) {
        if (vis[v] == 1)
            continue;
        vector<int> ndelta = delta;
        if (nodeVal!=goal[u])
            ndelta[curDepth%2]^=1;
        dfs(v, adj, vis, value, goal, curDepth + 1, ndelta, ans);
    }
}


void solve() {
	int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> value(n), goal(n), vis(n,0), ans;
    for(int i=0;i<n;i++)
        cin >> value[i];
    for(int i=0;i<n;i++)
        cin >> goal[i];
    dfs(0, adj, vis, value, goal, 0, {0,0}, ans);
    cout << ans.size() << "\n";
    for(int &num:ans)
        cout << num+1 << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
