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
    }
    vector<int>vis(n+1,0);
    vector<int> path, cycle;
    function<void(int)> dfs = [&](int u) {
        vis[u]=1;
        path.push_back(u);
        for(int &v:adj[u]) {
            if (vis[v]==2)
                continue;
            if (vis[v]==1) {
                if (cycle.empty()) {
                    auto itr = find(all(path), v);
                    for(;itr!=path.end();itr++)
                        cycle.push_back(*itr);
                    cycle.push_back(v);

                }
                continue;
            }
            dfs(v);
        }
        path.pop_back();
        vis[u]=2;
    };
    for(int i=1;i<=n&&cycle.empty();i++) {
        if (vis[i]!=0)
            continue;
        dfs(i);
    }
    if (cycle.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cycle.size() << "\n";
        for(int &v:cycle) {
            cout << v << " ";
        }
        cout <<  "\n";
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
