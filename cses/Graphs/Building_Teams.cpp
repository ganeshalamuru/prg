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
    vector<vector<int>>adj(n+1);
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>vis(n+1,-1);
    function<bool(int,int)> dfs=[&](int u, int c) {
        vis[u]=c;
        for(int &v:adj[u]) {
            if (vis[v]!=-1) {
                if (vis[v]==(c^1))
                    continue;
                else
                    return false;
            }
            if(!dfs(v,c^1))
                return false;
        }
        return true;
    };
    for(int i=1;i<=n;i++) {
        if (vis[i]!=-1)
            continue;
        if (!dfs(i,0)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    
    }
    for(int i=1;i<=n;i++) {
        cout << vis[i]+1 << " ";
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
