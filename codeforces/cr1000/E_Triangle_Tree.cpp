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
    vector<ll> sumofdepths(n,0);
    vector<int> numnodes(n,0), depthcnt(n,0), pdcnt(n,0), parent(n,0);
    function<void(int,int,int)> dfs = [&](int u, int p, int depth){
        depthcnt[depth]++;
        parent[u]=p;
        for(int &v:adj[u]) {
            if (v==p)
                continue;
            dfs(v,u,depth+1);
            numnodes[u]+=numnodes[v];
            sumofdepths[u]+=numnodes[v]+sumofdepths[v];
        }
        numnodes[u]++;
    };
    dfs(0, -1, 0);
    pdcnt[0] = depthcnt[0];
    for(int i=1;i<n;i++)
        pdcnt[i] = pdcnt[i-1] + depthcnt[i];
    ll ans = 0, diff;
    function<void(int, int, ll, ll, ll)> dfs2 = [&](int u, int p, ll sumofd, ll posnodes, ll pn2) {
        // adds all number less than < d1+d2
        ans+= sumofd+pn2-posnodes;
        // d2-d1
        diff+= sumofd - pn2;
        for(int &v:adj[u]) {
            if (v==p)
                continue;
            ll newpn = posnodes+numnodes[u]-numnodes[v]-1;
            dfs2(v, u, sumofd+sumofdepths[u]-(numnodes[v]+sumofdepths[v]), newpn, pn2+newpn);
        }
    };
    dfs2(0,-1,0,0,0);
    vector<vector<int>> nodes(n,vector<int>(3,0));
    queue<int> qq;
    qq.push(0);
    int prevsz = 0;
    while(!qq.empty()) {
        int sz = qq.size();
        for(int i=0;i<sz;i++) {
            int u = qq.front();
            qq.pop();
            int p = parent[u];
            if (p!=-1) {
                nodes[u]=nodes[p].F
            }

        }
        prevsz=sz;
    }

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
