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
	int n,k,s;
    cin >> n >> k >> s;
    vector<vector<int>> adj(n+1);
    for(int i=0,u,v;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dp(n+1,INT_MAX);
    vector<int> vis(n+1,0);
    auto dfs = [&](this auto self, int u) -> void {
        vis[u]=1;
        int minn=INT_MAX,secondminn=INT_MAX;
        for(int v:adj[u]) {
            if (vis[v]!=0)
                continue;
            self(v);
            if (dp[v]<minn) {
                swap(minn,secondminn);
                minn = dp[v];
            } else if (dp[v]<secondminn) {
                secondminn = dp[v];
            }
        }
        if (minn==INT_MAX) {
            dp[u]=0;
        } else if (secondminn==INT_MAX) {
            dp[u]=minn+1;
        } else {
            if (minn+secondminn+1<=k) {
                dp[u]=0;
            } else {
                dp[u] = minn+1;
            }
        }
    };
    dfs(s);
    if (dp[s]==0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}