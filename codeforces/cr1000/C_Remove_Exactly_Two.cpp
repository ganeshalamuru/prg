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
	int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n,0);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    int ans = INT_MIN;
    set<pii, greater<pii>> ss;
    for(int i=0;i<n;i++)
        ss.insert({deg[i], i});
    for(int i=0;i<n;i++) {
        int d = deg[i];
        ss.erase({d, i});
        for(int &v:adj[i]) {
            ss.erase({deg[v],v});
            deg[v]--;
            ss.insert({deg[v],v});
        }
        ans = max(ans, d+ss.begin()->first-1);
        for(int &v:adj[i]) {
            ss.erase({deg[v],v});
            deg[v]++;
            ss.insert({deg[v],v});
        }
        ss.insert({d,i});
    }
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
