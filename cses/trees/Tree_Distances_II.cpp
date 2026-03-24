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
	int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=1,a,b;i<n;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> dp(n+1,0),ndp(n+1);
    function<void(int,int)> dfs = [&](int u, int p) {
        ndp[u]++;
        for(int v:adj[u]) {
            if (v==p) continue;
            dfs(v,u);
            ndp[u]+=ndp[v];
            dp[u]+=ndp[v]+dp[v];
        }
    };
    dfs(1,0);
    function<void(int,int)> dfs2=[&](int u, int p) {
        for(int v:adj[u]) {
            if (v==p) continue;
            dp[v]=dp[u] + n - 2*ndp[v];
            dfs2(v,u);
        }
    };
    dfs2(1,0);
    for(int i=1;i<=n;i++) {
        cout << dp[i] << " ";
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
