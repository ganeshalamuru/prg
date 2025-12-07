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
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    ll mincost = 0;
    vector<int> vis(n+1,0);
    pq.push({0,1});
    while (!pq.empty()) {
        auto [c,u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        mincost+=c;
        for(auto &[v, edgecost]:adj[u]) {
            pq.push({edgecost,v});
        }
    }
    if (find(vis.begin()+1,vis.end(),0)==vis.end()) {
        cout << mincost << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
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
