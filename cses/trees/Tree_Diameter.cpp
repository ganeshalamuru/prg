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
    vector<int> dp(n+1,0),vis(n+1,0);
    int maxdis = 0;
    function<void(int)> dfs = [&](int u) {
        vis[u]=1;
        int curchildmaxdis = 0;
        for(int v:adj[u]) {
            if (vis[v]==0) {
                dfs(v);
                maxdis = max(maxdis, curchildmaxdis + dp[v]+1);
                curchildmaxdis = max(curchildmaxdis,dp[v]+1);
            }
        }
        dp[u]=curchildmaxdis;
    };
    dfs(1);
    cout << maxdis << "\n";

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
