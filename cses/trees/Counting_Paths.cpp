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
	int n,m;
    cin >> n >> m;
    vector<vector<int>> jump(18,vector<int>(n+1)), adj(n+1);
    for(int i=1,a,b;i<n;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(n+1);
    function<void(int,int)> dfs = [&](int u,int p) {
        jump[0][u]=p;
        for(int v:adj[u]) {
            if (v==p) continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    };
    dfs(1,0);
    for(int j=1;j<18;j++) {
        for(int i=1;i<=n;i++) {
            if (jump[j-1][i]!=0)
                jump[j][i] = jump[j-1][jump[j-1][i]];
        }
    }
    vector<int> dp(n+1,0);
    for(int i=1,a,b;i<=m;i++) {
        cin >> a >> b;
        if (depth[a]>depth[b]) {
            swap(a,b);
        }
        dp[a]++,dp[b]++;
        int depthdiff = depth[b]-depth[a];
        for(int j=17;j>=0;j--) {
            if ((depthdiff>>j)&1)
                b = jump[j][b];
        }
        int lca=0;
        if (a==b) {
            lca=a;
        } else {
            int tempa=a,tempb=b;
            for(int j=17;j>=0;j--) {
                if (jump[j][tempa]!=jump[j][tempb])
                    tempa=jump[j][tempa],tempb=jump[j][tempb];
            }
            lca = jump[0][tempa];
        }
        dp[lca]--;
        dp[jump[0][lca]]--;
    }
    function<void(int,int)> dfs2=[&](int u,int p) {
        for(int v:adj[u]) {
            if (v==p) continue;
            dfs2(v,u);
            dp[u]+=dp[v];
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
