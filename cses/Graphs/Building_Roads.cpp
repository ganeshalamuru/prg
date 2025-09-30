#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    for(int i=0,u,v;i<m;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n,0);
    function<void(int)> dfs = [&](int u) {
        vis[u]=1;
        for(int &v:adj[u]) {
            if (vis[v]==1)
                continue;
            dfs(v);
        }
    };
    vector<int> ccs;
    for(int i=0;i<n;i++) {
        if (vis[i]!=0)
            continue;
        dfs(i);
        ccs.push_back(i);
    }
    if (ccs.size()==1) {
        cout << 0 << "\n";
    } else {
        cout << ccs.size()-1 << "\n";
        for(int i=1;i<ccs.size();i++) {
            cout << ccs[i-1]+1 << " " << ccs[i]+1 << "\n";
        }
    }
}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
