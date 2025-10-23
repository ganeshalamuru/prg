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
    vector<vector<int>> adj(n+1);
    for(int i=0,u,v;i<m;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0),dis(n+1,INT_MAX),parent(n+1,-1);
    dis[1]=0;
    vis[1]=1;
    set<pii> ss;
    ss.insert({0,1});
    while(!ss.empty()) {
        auto node = *ss.begin();
        ss.erase(node);
        for(int &v:adj[node.S]) {
            if (vis[v]==0) {
                vis[v]=1;
                parent[v]=node.S;
                dis[v]=node.F+1;
                ss.insert({dis[v],v});
            } else if (dis[v]>node.F+1){
                ss.erase({dis[v],v});
                parent[v]=node.S;
                dis[v]=node.F+1;
                ss.insert({dis[v],v});
            }
        }
    }
    if (dis[n]==INT_MAX) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    stack<int> route;
    int curnode = n;
    while(curnode!=-1) {
        route.push(curnode);
        curnode=parent[curnode];
    }
    cout << route.size() << "\n";
    while(!route.empty()) {
        cout << route.top() << " ";
        route.pop();
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
