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

const int mod = 1e9+7;
vector<vector<int>> dp(1<<19,vector<int>(19));

void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n,vector<int>(n));
    for(int i=1,a,b;i<=m;i++) {
        cin >> a >> b;
        a--,b--;
        adj[a][b]++;
    }
    for(int z=0;z<n-1;z++)
        dp[(1<<z)][z]=adj[z][n-1];
    for(int i=1;i<(1<<(n-1));i++) {
        if ((i&(i-1))==0)
            continue;
        for(int j=0;j<n-1;j++) {
            if ((i>>j)&1) {
                for(int z=0;z<n-1;z++) {
                    if ((i>>z)&1) {
                        dp[i][j]=(dp[i][j] + int((1ll*dp[i^(1<<j)][z]*adj[j][z])%mod) )%mod;
                    }
                }
            }
        }
    }
    cout << dp[(1<<(n-1))-1][0] << "\n";

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
