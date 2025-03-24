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
	int n,x;
    cin >> n >> x;
    vector<vector<pii>> foods(3);
    for(int i=0,v,a,c;i<n;i++) {
        cin >> v >> a >> c;
        v--;
        foods[v].push_back({a,c});
    }
    // dp[i][j] = max units of vit i you can consume 
    // if you are allowed to eat atmost j calroies
    vector<vector<int>> dp(3,vector<int>(x+1,0));
    for(int i=0;i<3;i++) {
        for(int j=0;j<foods[i].size();j++) {
            int curcalroies = foods[i][j].S;
            int vitunits = foods[i][j].F;
            for(int z=x;z>=curcalroies;z--) {
                dp[i][z] = max(dp[i][z], dp[i][z-curcalroies]+vitunits);
            }
        }
    }
    vector<int> dp2(x+1,0);
    for(int z=1;z<=x;z++) {
        for(int m=1;m<=z;m++)
            dp2[z] = max(dp2[z],min(dp[1][m],dp[2][z-m]));
    }
    int ans = 0;
    for(int z=1;z<=x;z++) {
        ans = max(ans,min(dp[0][z],dp2[x-z]));
    }
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
