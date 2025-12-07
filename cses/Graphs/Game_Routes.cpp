#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const int mod = 1e9l+7;


void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int>vis(n+1),dp(n+1,0);
    function<void(int)> dfs=[&](int u) {
        vis[u]=1;
        for(int &v:adj[u]) {
            if (vis[v]==0)
                dfs(v);
            dp[u]=(dp[u]+dp[v])%mod;
        }
        if (u==n)
            dp[u]=1;
    };
    dfs(1);
    cout << dp[1] << "\n";

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
