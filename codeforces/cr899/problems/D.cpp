#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e5+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


vector<ll> vis(N,0),dpsub(N,0);
vector<vector<vector<ll>>> dp(N,vector<vector<ll>>(20,vector<ll>(2,0)));

void resetvec(int n,vector<ll>&v) {
    for(int i=0;i<n;i++)
        v[i]=0;
}

void init(int n) {
    for(int i=0;i<n;i++) {
        vis[i]=0;
        dpsub[i]=0;
        for(int j=0;j<20;j++)
            dp[i][j][0]=0, dp[i][j][1]=0;
    }
}


void dfssubtree(int u, vector<vector<int>> &edges) {
    vis[u]=1;
    int sz = 1;
    for(int &v:edges[u]) {
        if (vis[v]!=1)
            dfssubtree(v,edges);
        sz+=dpsub[v];
    }
    dpsub[u]=sz;
}

void dfs(int u,vector<vector<int>> &edges,vector<ll> &a) {
    vis[u]=1;
    vector<vector<ll>> cost(20,vector<ll>(2,0));
    for(int bit=0;bit<20;bit++) {
        int cur = (a[u]>>bit)&1;
        cost[bit][cur^1] += dpsub[u]*(1<<bit); 
    }
    for(int &v:edges[u]) {
        if (vis[v]!=1) {
            dfs(v,edges,a);
            for(int bit=0;bit<20;bit++) {
                int cur = (a[u]>>bit)&1;
                cost[bit][cur] += dp[v][bit][cur];
                cost[bit][cur^1] += dp[v][bit][cur];
            }
        }
    }
    dp[u] = cost;
}

void dfs2(int u, int numnodes, vector<vector<ll>> &cost, vector<vector<int>> &edges,vector<ll>&a, vector<ll> &res) {
    vis[u]=1;
    for(int bit=0;bit<20;bit++) {
        int bitval = (a[u]>>bit)&1;
        res[u] += dp[u][bit][bitval] + cost[bit][bitval];
    }
    for(int &v:edges[u]) {
        if(vis[v]!=1) {
            vector<vector<ll>> cost2(20,vector<ll>(2,0));
            for(int bit=0;bit<20;bit++) {
                int cur = (a[u]>>bit)&1;
                cost2[bit][cur^1] = (dp[u][bit][cur^1]+(1<<bit)*(numnodes-dpsub[v]) - dp[v][bit][cur]+cost[bit][cur]);
                cost2[bit][cur] = (cost[bit][cur]+dp[u][bit][cur]-dp[v][bit][cur]);
            }
            dfs2(v,numnodes + dpsub[u]-dpsub[v],cost2, edges, a, res);
        }
    }
}

void solve(){
	int n;
    cin >> n;
    init(n);
    vector<ll>a(n);
    for(ll &i:a)
        cin >> i;
    vector<vector<int>> edges(n);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfssubtree(0, edges);

    resetvec(n, vis);
    dfs(0,edges,a);

    vector<ll> res(n,0);
    vector<vector<ll>> cost(20,vector<ll>(2,0));
    resetvec(n, vis);
    dfs2(0,0,cost, edges, a, res);

    for(int i=0;i<n;i++)
        cout << res[i] << " \n"[i==n-1];
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
