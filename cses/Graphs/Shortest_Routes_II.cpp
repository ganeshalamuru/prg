#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll INF=1e18l;

void solve() {
	int n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INF));
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        dp[a][b]=min(dp[a][b], 1ll*c);
        dp[b][a]=min(dp[b][a], 1ll*c);
    }
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int k=1;k<=n;k++) {
        for(int u=1;u<=n;u++) {
            for(int v=1;v<=n;v++) { 
                dp[u][v]=min(dp[u][v], dp[u][k]+dp[k][v]);
            }   
        }
    }
    while (q--) {
        int u,v;
        cin >> u >> v;
        if (dp[u][v]==INF) {
            cout << -1 << "\n";
        } else {
            cout << dp[u][v] << "\n";
        }
    }

}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
