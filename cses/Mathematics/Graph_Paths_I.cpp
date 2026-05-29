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

const int MOD = 1e9+7;

vector<vector<int>> matmul(int n,auto &a, auto &b) {
    vector<vector<int>> res(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int z=1;z<=n;z++) {
                res[i][j]=(res[i][j]+int((1ll*a[i][z]*b[z][j])%MOD))%MOD;
            }
        }
    }
    return res;
}

void solve() {
	int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n+1,vector<int>(n+1));
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        adj[a][b]++;
    }
    vector<vector<int>> res(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
        res[i][i]=1;
    while (k>0) {
        if (k&1) {
            res = matmul(n,res,adj);
        }
        adj = matmul(n,adj,adj);
        k>>=1;
    }
    cout << res[1][n] << "\n";


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
