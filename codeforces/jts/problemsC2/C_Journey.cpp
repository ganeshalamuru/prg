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


void dfs(int u, vector<vector<int>> &adj, vector<int> &vis, ld probability, ll len, long double &ans) {
    vis[u] = 1;
    int numchild = (int)(adj[u].size()) - 1;
    if (numchild == 0) {
        ans += (1.0l*len)*probability;
        return;
    }
    for(int v:adj[u]) {
        if (vis[v] == 1)
            continue;
        dfs(v, adj, vis, probability*(1.0l/numchild), len+1, ans);
    }  
}



void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    adj[0].push_back(1);
    adj[1].push_back(0);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    long double ans = 0;
    vis[0] = 1;
    dfs(1, adj, vis, 1.0l, 0, ans);
    cout << fixed << setprecision(10) << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
