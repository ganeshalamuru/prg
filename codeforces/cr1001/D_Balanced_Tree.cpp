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


void dfs(int u, int p, vector<vector<int>> &adj, vector<vector<int>> &valrange, vector<int> &val) {
    int maxcval = INT_MIN;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs(v, u, adj, valrange, val);
        maxcval = max(maxcval, val[v]);
    }
    if (maxcval <= valrange[u][0])
        val[u]=valrange[u][0];
    else
        val[u]=min(valrange[u][1], maxcval);
}

ll dfs2(int u, int p, vector<vector<int>>&adj, vector<int> &val) {
    ll ans = 0;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        ans+=max(val[v]-val[u],0)+ dfs2(v,u,adj,val);
    }
    return ans;
}


void solve() {
	int n;
    cin >> n;
    vector<vector<int>> valrange(n,vector<int>(2));
    for(int i=0,l,r;i<n;i++) {
        cin >> l >> r;
        valrange[i][0]=l;
        valrange[i][1]=r;
    }
    vector<vector<int>> adj(n);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> val(n,-1);
    dfs(0, -1, adj, valrange, val);
    cout << val[0]+dfs2(0, -1, adj, val) << "\n"; 
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
