#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
 
 
void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    map<pii,int> edges;
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        auto itr=edges.find({a,b});
        if (itr==edges.end()) {
            edges[{a,b}]=-c;
        } else {
            itr->S = min(itr->S,-c);
        }
    }
    for(auto &[edge,c]:edges) {
        auto [u,v]=edge;
        adj[u].push_back({v,c});
    }
    vector<int> vis(n+1),innpath(n+1);
    function<void(int)> dfs=[&](int u) {
        vis[u]=1;
        for(auto &[v,_]:adj[u]) {
            if (vis[v]==2) {
                innpath[u]|=innpath[v];
            } else if (vis[v]==1) {
                continue;
            } else {
                dfs(v);
                innpath[u]|=innpath[v];
            }
        }
        innpath[u] |= (u==n);
        vis[u]=2;
    };
    dfs(1);
    vector<ll> dis(n+1,LLONG_MAX);
    dis[1]=min(0,edges[{1,1}]);
    for(int i=1;i<n;i++) {
        bool change = false;
        for(auto &[edge,c]:edges) {
            auto [u,v]=edge;
            if (dis[u]<LLONG_MAX && dis[u]+c<dis[v]) {
                change=true;
                dis[v]=dis[u]+c;
            }
        }
        if (!change) {
            break;
        }
    }
    vector<ll>ndis(all(dis));
 
    for(int i=1;i<=n;i++) {
        for(auto &[edge,c]:edges) {
            auto [u,v]=edge;
            if (ndis[u]<LLONG_MAX && ndis[u]+c<ndis[v]) {
                ndis[v]=ndis[u]+c;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if (innpath[i]==1 && ndis[i]<dis[i]) {
            cout << -1 << "\n";
            return;
        }
    }
 
    cout << -dis[n] << "\n";
 
 
}
 
 
int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
