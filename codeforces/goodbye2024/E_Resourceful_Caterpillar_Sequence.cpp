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



void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &nt) {
    int t=INT_MAX;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs(v,u,adj,nt);
        t=min(nt[v],t);
    }
    if (t==INT_MAX)
        nt[u]=0;
    else
        nt[u] = min(2,t+1);
}

void dfs2(int u, int p, vector<vector<int>> &adj, vector<vector<int>> &dp, vector<int>&nt) {
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs2(v,u,adj,dp,nt);
        for(int j=0;j<3;j++)
            dp[u][j]+=dp[v][j];
    }
    dp[u][nt[u]]++;
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
    if (n==2) {
        cout << 0 << "\n";
        return;
    }
    int root;
    for(int i=0;i<n;i++) {
        if (adj[i].size() > 1) {
            root = i;
            break;
        }
    }
    vector<int> nodetype(n);
    dfs(root, -1, adj, nodetype);
    int numleaves = 0;
    for(int i=0;i<n;i++)
        numleaves+=(nodetype[i]==0);
    ll ans = 1ll*numleaves*(n-numleaves);
    vector<vector<int>> dp(n,vector<int>(3,0));
    dfs2(root, -1,adj, dp, nodetype);
    function<void(int, int, ll)> dfs3 = [&](int u, int p, ll numtypetwos) {
        int ut =nodetype[u];
        for(int &v:adj[u]) {
            if (v==p)
                continue;
            int vt = nodetype[v];
            if (ut == 1 && vt == 1) {
                ans+=numtypetwos+dp[u][2];
            } else if (ut == 1 && vt == 2) {
                ans+=numtypetwos+dp[u][2]-dp[v][2];
            } else if (ut == 2 && vt == 1) {
                ans+=dp[v][2];
            }
            dfs3(v, u, numtypetwos+dp[u][2]-dp[v][2]);
        }
    };
    dfs3(root, -1, 0ll);
    cout << ans << "\n";
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
