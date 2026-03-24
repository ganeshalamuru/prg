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
    function<void(int,int)> dfs = [&](int u, int p) {
        for(int v:adj[u]) {
            if (v==p) continue;
            dfs(v,u);
            if (1+dp[v][0]>dp[u][0]) {
                swap(dp[u][0],dp[u][1]),dp[u][0]=1+dp[v][0];
            } else if (1+dp[v][0]>dp[u][1]) {
                dp[u][1]=1+dp[v][0];
            }
        }
    };
    dfs(1,0);
    function<void(int,int)> dfs2=[&](int u, int p) {
        for(int v:adj[u]) {
            if (v==p) continue;
            if (dp[u][0]==1+dp[v][0]) {
                if (1+dp[u][1]>dp[v][0]) {
                    swap(dp[v][0],dp[v][1]),dp[v][0] = 1+dp[u][1];
                } else if (1+dp[u][1]>dp[v][1]) {
                    dp[v][1]=1+dp[u][1];
                }
            } else {
                if (1+dp[u][0]>dp[v][0]) {
                    swap(dp[v][0], dp[v][1]),dp[v][0] = 1+dp[u][0];
                } else if (1+dp[u][0]>dp[v][1]) {
                    dp[v][1]=1+dp[u][0];
                }
            }
            dfs2(v,u);
        }
    };
    dfs2(1,0);
    for(int i=1;i<=n;i++) {
        cout << dp[i][0] << " ";
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
