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




void solve() {
	int n,m,x;
    cin >> n >> m >> x;
    vector<vector<vector<int>>> adj(n,vector<vector<int>>(2));
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u][0].push_back(v);
        adj[v][1].push_back(u);
    }
    set<vector<ll>> ss;
    vector<vector<ll>> cost(n,vector<ll>(2,LLONG_MAX));
    cost[0][0]=0;
    cost[0][1]=x;
    ss.insert({0,0,0});
    ss.insert({x,1,0});
    while(!ss.empty()) {
        auto tp = *ss.begin();
        ss.erase(tp);
        for(int &v:adj[tp[2]][tp[1]]) {
            if (cost[v][tp[1]]>tp[0]+1) {
                ss.erase({cost[v][tp[1]],tp[2],v});
                cost[v][tp[1]]=tp[0]+1;
                ss.insert({tp[0]+1,tp[1],v});
            }
        }
        for(int &v:adj[tp[2]][tp[1]^1]) {
            if (cost[v][tp[1]^1]>tp[0]+x+1) {
                ss.erase({cost[v][tp[1]^1],tp[2],v});
                cost[v][tp[1]^1]=tp[0]+x+1;
                ss.insert({tp[0]+x+1,tp[1]^1,v});
            }
        }
    }
    cout << min(cost[n-1][0],cost[n-1][1]) << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
