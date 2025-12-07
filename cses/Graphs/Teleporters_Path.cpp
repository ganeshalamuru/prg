#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	int n,m;
    cin >> n >> m;
    vector<set<int>> adj(n+1);
    vector<int> indeg(n+1),outdeg(n+1);
    for(int i=1,a,b;i<=m;i++) {
        cin >> a >> b;
        adj[a].insert(b);
        outdeg[a]++;
        indeg[b]++;
    }
    for(int i=2;i<n;i++) {
        if (indeg[i]!=outdeg[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    if (outdeg[1]-indeg[1]!=1 || indeg[n]-outdeg[n]!=1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> path;
    function<void(int)> dfs = [&](int u) {
        while(!adj[u].empty()) {
            int v = *adj[u].begin();
            adj[u].erase(v);
            dfs(v);
        }
        path.push_back(u);
    };
    dfs(1);
    for(int i=1;i<=n;i++) {
        if (!adj[i].empty()) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    reverse(all(path));
    for(int v:path) {
        cout << v << " ";
    }
    cout << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
