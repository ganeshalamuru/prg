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
	int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    for(int i=0,u,v,w;i<m;i++) {
        cin >> u >> v >> w;
        u--,v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> vis(n,0), rpxorval(n,0);
    vector<vector<pii>> ccnums;
    function<bool(int, int)> dfs = [&](int u, int rpxorv) {
        vis[u] = 1;
        rpxorval[u]=rpxorv;
        ccnums.back().push_back({u,rpxorv});
        for(auto &v:adj[u]) {
            if (vis[v.F]==1) {
                if ((rpxorv^v.S) != rpxorval[v.F])
                    return false;
                continue;
            }
            if(!dfs(v.F,rpxorv^v.S))
                return false;
        }
        return true;
    };
    for(int i=0;i<n;i++) {
        if (vis[i]!=0)
            continue;
        ccnums.push_back(vector<pii>());
        if (!dfs(i,0)) {
            cout << -1 << "\n";
            return;
        }
    }
    vector<int> ans(n);
    for(int i=0;i<ccnums.size();i++) {
        int nums = ccnums[i].size();
        vector<int> bitfreq(31,0);
        for(int j=0;j<nums;j++) {
            bitset<31> bs(ccnums[i][j].S);
            for(int z=0;z<31;z++) {
                bitfreq[z]+=bs[z];
            }
        }
        int basenum = 0;
        for(int z=0;z<31;z++) {
            if (bitfreq[z]>=(nums+1)/2)
                basenum|=(1<<z);
        }
        for(int j=0;j<nums;j++)
            ans[ccnums[i][j].F]=basenum^ccnums[i][j].S;
    }
    for(int &num:ans)
        cout << num << " ";
    cout << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
