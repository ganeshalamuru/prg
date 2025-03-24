#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}




void solve() {
	int m;
    cin >> m;
    int n = (powe(3,m+1)-1)/2;
    string s;
    cin >> s;
    vector<vector<int>> dp(n,vector<int>(2,0));
    function<void(int)> dfs = [&](int u) {
        if (u*3+1>=n) {
            dp[u][(s[u-((powe(3,m)-1)/2)]-'0')^1]=1;
            return;
        }
        for(int v:{3*u+1,3*u+2,3*u+3}) {
            dfs(v);
        }
        int zconvcost = INT_MAX;
        for(auto &cc:vector<vector<int>>{{0,0,0},{0,0,1},{0,1,0},{1,0,0}}) {
            int cost = 0;
            for(int r=1;r<=3;r++) {
                cost+=dp[3*u+r][cc[r-1]];
            }
            zconvcost=min(zconvcost, cost);
        }
        dp[u][0]=zconvcost;
        int oneconvcost = INT_MAX;
        for(auto &cc:vector<vector<int>>{{1,1,1},{1,1,0},{1,0,1},{0,1,1}}) {
            int cost = 0;
            for(int r=1;r<=3;r++) {
                cost+=dp[3*u+r][cc[r-1]];
            }
            oneconvcost=min(oneconvcost, cost);
        }
        dp[u][1]=oneconvcost;
    };
    dfs(0);
    cout << max(dp[0][0],dp[0][1]) << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
