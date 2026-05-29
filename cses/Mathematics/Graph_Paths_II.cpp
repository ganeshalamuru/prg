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

const ll INF = 1e18l+1;

vector<vector<ll>> matmul(int n, auto &a, auto &b) {
    vector<vector<ll>> res(n+1,vector<ll>(n+1,INF));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int z=1;z<=n;z++) {
                res[i][j] = min(res[i][j], a[i][z]+b[z][j]);
            }
        }
    }
    return res;

}

void solve() {
	int n,m,k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n+1,vector<ll>(n+1,INF));
    for(int i=1,a,b,w;i<=m;i++) {
        cin >> a >> b >> w;
        adj[a][b] = min(adj[a][b],1ll*w);
    }
    vector<vector<ll>> res(n+1,vector<ll>(n+1,INF));
    for(int i=1;i<=n;i++)
        res[i][i]=0;
    while (k>0) {
        if (k&1)
            res = matmul(n,res,adj);
        adj = matmul(n,adj,adj);
        k>>=1;
    }
    if (res[1][n] == INF) {
        cout << -1 << "\n";
    } else {
        cout << res[1][n] << "\n";
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
