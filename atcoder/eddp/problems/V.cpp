#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;

ll mod;
int madd (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a + b)%mod;
}
int msub (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a - b + mod)%mod;
}
int mmul (ll a, ll b){
    a = a%mod, b = b%mod;
	return (1ll * a * b)%mod;
}


void dfs(int u, vector<vector<int>> &edges, vector<ll>& vis, vector<ll> &dp,vector<ll>& dp2) {
    vis[u] = 1;
    ll numways = 1;
    vector<int> children;
    for(int v:edges[u]) {
        if (vis[v])
            continue;
        children.push_back(v);
        dp2[v] = numways;
        dfs(v,edges, vis, dp, dp2);
        numways = mmul(numways, madd(1, dp[v]));
    }
    ll tt = 1;
    reverse(children.begin(), children.end());
    for(int v:children) {
        dp2[v] = mmul(dp2[v], tt);
        tt = mmul(tt, madd(1,dp[v]));
    }
    dp[u]=numways;
}

void dfs2(int u,ll numwayspath, vector<vector<int>> &edges, vector<ll>& vis, vector<ll>&dp, vector<ll>& dp2, vector<ll>& dp3) {
    vis[u]=1;
    dp3[u] = mmul(madd(1,numwayspath), dp[u]);
    for(int v:edges[u]) {
        if (vis[v])
            continue;
        dfs2(v,mmul(madd(1,numwayspath), dp2[v]), edges, vis, dp, dp2, dp3);
    }
}

void solve(){
	ll n;
    cin >> n >> mod;
    vector<vector<int>> edges(n);
    for(int i=0,x,y;i<n-1;i++) {
        cin >> x >> y;
        x--,y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<ll>dp(n,0),dp2(n,0),vis(n,0);
    dfs(0,edges,vis,dp, dp2);
    vis = vector<ll>(n,0);
    vector<ll>dp3(n,0);
    dfs2(0, 0, edges, vis, dp, dp2, dp3);
    for(ll ans:dp3)
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
