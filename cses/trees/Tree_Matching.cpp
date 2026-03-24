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
    vector<vector<int>> dp(n+1,{0,0});
    vector<int> vis(n+1,0);
    function<void(int)> dfs = [&](int u) {
        vis[u]=1;
        for(int v:adj[u]) {
            if (vis[v]==0) {
                dfs(v);
                dp[u][0] = max(dp[u][1]+dp[v][1]+1,dp[u][0]+max(dp[v][0],dp[v][1]));
                dp[u][1]+=max(dp[v][0], dp[v][1]);   
            }
        }
    };
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";


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
