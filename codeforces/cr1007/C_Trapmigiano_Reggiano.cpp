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


void dfs(int u, int p,int en, vector<vector<int>> &adj, vector<int>&path, vector<int> &stenpath) {
    path.push_back(u);
    if (u==en)
        stenpath=path;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs(v,u,en,adj,path,stenpath);
    }
    path.pop_back();
}

void dfs2(int u, int p, vector<vector<int>>&adj, vector<int>&ans) {
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs2(v,u,adj,ans);
    }
    ans.push_back(u);
}

void solve() {
	int n,st,en;
    cin >> n >> st>>en;
    st--,en--;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> stenpath,path;
    dfs(st,-1,en,adj,path,stenpath);
    vector<int> ans;
    int prev=-1;
    for(int i=0;i<stenpath.size();i++) {
        for(int &v:adj[stenpath[i]]) {
            if (v==prev || (i+1<stenpath.size() && v==stenpath[i+1]))
                continue;
            dfs2(v,stenpath[i],adj,ans);
        }
        ans.push_back(stenpath[i]);
        prev = stenpath[i];
    }
    for(int i=0;i<ans.size();i++)
        cout << ans[i]+1 << " ";
    cout << "\n";
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
