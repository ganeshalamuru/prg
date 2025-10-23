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
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    vector<int> path,bcycle;
    function<void(int,int)> dfs=[&](int u, int p) {
        vis[u]=1;
        path.push_back(u);
        for(int &v:adj[u]) {
            if (v==p)
                continue;
            if (vis[v]!=0) {
                if (bcycle.empty()) {
                    auto itr = find(all(path),v);
                    bcycle=vector<int>(itr,path.end()),bcycle.push_back(v);
                }
                continue;
            }
            dfs(v,u);
        }
        path.pop_back();
    };
    for(int i=1;i<=n && bcycle.empty();i++) {
        if (vis[i]!=0)
            continue;
        dfs(i,0);
    }
    if (bcycle.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << bcycle.size() << "\n";
        for(int &node:bcycle) {
            cout << node << " ";
        }
        cout << "\n";
    }

}


int main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
