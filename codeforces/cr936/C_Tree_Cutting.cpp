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

int dfs(int u, vector<vector<int>> &adj, vector<int> &vis, int allowedsubtsz, int &numValidCompo, int &numNodesInRootCompo) {
    vis[u] = 1;
    int subsize = 1;
    for(int& v:adj[u]) {
        if (vis[v]==1)
            continue;
        subsize += dfs(v, adj, vis, allowedsubtsz, numValidCompo, numNodesInRootCompo);
    }
    if (subsize >= allowedsubtsz && numNodesInRootCompo-subsize>=allowedsubtsz) {
        numNodesInRootCompo -= subsize;
        numValidCompo++;
        return 0;
    }
    return subsize;
}


bool check(int x, int k, vector<vector<int>> &adj) {
    int n = adj.size();
    if (x > n)
        return false;
    int numValidCompo = 1, numNodesInRootCompo = n;
    vector<int> vis(n, 0);
    dfs(0,adj, vis, x, numValidCompo, numNodesInRootCompo);
    return numValidCompo >= k+1;
}

void solve() {
	int n,k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l=1,r=n;
    while(l<r) {
        int mid = l + (r-l+1) / 2;
        if (check(mid, k, adj)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << "\n";
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
