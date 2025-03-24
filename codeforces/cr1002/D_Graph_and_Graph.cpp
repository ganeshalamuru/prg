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
	int n,s1,s2;
    cin >> n >> s1 >> s2;
    s1--,s2--;
    int m1,m2;
    cin >> m1;
    vector<vector<int>> adj(n),adj2(n);
    set<pii> edges;
    for(int i=0,u,v;i<m1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.insert({u,v}),edges.insert({v,u});
    }
    cin >> m2;
    set<int> good;
    for(int i=0,u,v;i<m2;i++) {
        cin >> u >> v;
        u--,v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        if (edges.find({u,v}) != edges.end()) {
            good.insert(u),good.insert(v);
        }
    }
    vector<vector<int>> dis(n,vector<int>(n, INT_MAX));
    set<pair<int, pii>> ss;
    dis[s1][s2] = 0;
    ss.insert({0,{s1,s2}});
    while(!ss.empty()) {
        auto tt = *ss.begin();
        ss.erase(ss.begin());
        for(int &v1:adj[tt.S.F]) {
            for(int &v2:adj2[tt.S.S]) {
                int cost = abs(v1-v2);
                if (tt.F+cost < dis[v1][v2]) {
                    ss.erase({dis[v1][v2], {v1,v2}});
                    dis[v1][v2] = tt.F+cost;
                    ss.insert({dis[v1][v2], {v1,v2}});
                }
            }
        }
    }

    int ans = INT_MAX;
    for(auto &v:good)
        ans = min(ans, dis[v][v]);
    
    if (ans == INT_MAX)
        cout << -1 << "\n";
    else
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
