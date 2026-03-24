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
    vector<vector<int>> dp(18,vector<int>(n+1,-1)),adj(n+1);
    for(int i=2;i<=n;i++) {
        cin >> dp[0][i];
        adj[dp[0][i]].push_back(i);
    }
    for(int j=1;j<18;j++) {
        for(int i=1;i<=n;i++) {
            if (dp[j-1][i]!=-1)
                dp[j][i]=dp[j-1][dp[j-1][i]];
        }
    }
    vector<int> depth(n+1,0);
    function<void(int,int)> dfs = [&](int u, int p) {
        for(int v:adj[u]) {
            if(v==p) continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    };
    dfs(1,0);
    while (q--) {
        int a,b;
        cin >> a >> b;
        auto findktpa = [&](int u,int k) {
            int pa = u;
            for(int i=17;i>=0 && pa!=-1;i--) {
                if ((k>>i)&1)
                    pa=dp[i][pa];
            }
            return pa;
        };
        if (depth[a]>depth[b])
            swap(a,b);
        b=findktpa(b,depth[b]-depth[a]);
        if (a==b) {
            cout << a << "\n";
        } else if (a!=b) {
            for(int j=17;j>=0;j--)
                if (dp[j][a]!=dp[j][b])
                    a=dp[j][a],b=dp[j][b];
            cout << dp[0][a] << "\n";
        }
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
