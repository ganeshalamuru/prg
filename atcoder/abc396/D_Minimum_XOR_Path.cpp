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



vector<vector<ll>> cost(10,vector<ll>(10,LLONG_MAX));
vector<vector<int>> adj(10);

vector<int> vis(10,0);
ll ans = LLONG_MAX,pathxor = 0;

void dfs(int u, int e) {
    if (u==e) {
        ans = min(ans, pathxor);
        return;
    }
    vis[u]=1;
    for(int &v:adj[u]) {
        if (vis[v]==1)
            continue;
        pathxor^=cost[u][v];
        dfs(v,e);
        pathxor^=cost[u][v];
    }
    vis[u]=0;
}

void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u][v]=cost[v][u]=w;
    }
    dfs(0,n-1);
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
