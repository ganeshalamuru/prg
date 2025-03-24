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
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans(n),vis(n,0);
    vector<int>trav{1,n};
    int ind = 0;
    queue<int> qq;
    qq.push(0),vis[0]=1;
    while(qq.size()>0) {
        int sz = qq.size();
        while(sz--) {
            int node = qq.front();
            qq.pop();
            ans[node]=2*trav[ind];
            trav[ind]+=ind==0?1:-1;
            for(int &v:adj[node]) {
                if (vis[v]==1)
                    continue;
                vis[v]=1;
                qq.push(v);
            }
        }
        ind^=1;
    }
    function<void(int, int)> dfs=[&](int u, int p) {
        for(int &v:adj[u]) {
            if (v==p)
                continue;
            if (abs(ans[u]-ans[v])==2)
                ans[v]=ans[u]-1;
            dfs(v,u);
        }
    };
    dfs(0,-1);
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
    cout << "\n";
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
