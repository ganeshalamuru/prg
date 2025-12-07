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
        adj[b].push_back(a);
    }
    vector<int> vis(n+1),postorder;
    function<bool(int)> dfscycle = [&](int u) {
        vis[u]=1;
        bool cycle = false;
        for(int &v:adj[u]) {
            if (vis[v]==2)
                continue;
            if (vis[v]==1)
                return true;
            cycle=cycle||dfscycle(v);
        }
        postorder.push_back(u);
        vis[u]=2;
        return cycle;
    };
    for(int i=1;i<=n;i++) {
        if (vis[i]!=0)
            continue;
        if (dfscycle(i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for(int &v:postorder) {
        cout << v << " ";
    }
    cout << "\n";

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
