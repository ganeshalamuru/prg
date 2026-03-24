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
	int n,q;
    cin >> n >> q;
    vector<vector<int>> dp(18,vector<int>(n+1)),adj(n+1);
    for(int i=1,a,b;i<n;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(n+1,0);
    function<void(int,int)> dfs = [&](int u, int p) {
        dp[0][u]=p;
        for(int v:adj[u]) {
            if (v==p) continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    };
    dfs(1,0);
    for(int j=1;j<18;j++) {
        for(int i=1;i<=n;i++) {
            if (dp[j-1][i]!=0)
                dp[j][i]=dp[j-1][dp[j-1][i]];
        }
    }
    while(q--) {
        int a,b;
        cin >> a >> b;
        if (depth[a]>depth[b]) {
            swap(a,b);
        }
        int depthdiff = depth[b]-depth[a];
        for(int i=17;i>=0;i--) {
            if ((depthdiff>>i)&1)
                b = dp[i][b];
        }
        if (a==b) {
            cout << depthdiff << "\n";
            continue;
        }
        int tempa=a,tempb=b;
        for(int i=17;i>=0;i--) {
            if (dp[i][tempa]!=dp[i][tempb])
                tempa = dp[i][tempa],tempb = dp[i][tempb];
        }
        int lca = dp[0][tempa];
        cout << depthdiff + depth[a] + depth[b] - 2*depth[lca] << "\n";
    }


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
