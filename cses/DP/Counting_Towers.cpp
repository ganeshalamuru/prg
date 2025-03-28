#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+1, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}




vector<vector<int>> dp(N,vector<int>(4,0));

//  if i is odd dp[i][0] -- vertical line is removed, dp[i][1] -- vertical line is present 
//  if i is even dp[i][0] -- both horx lines removed, dp[i][1] -- only right horz line present
//                dp[i][2] -- only left horz present, dp[i][3] -- both horz lines present 
void calc() {
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<N;i++) {
        if (i%2==0) {
            dp[i][0] = (dp[i-1][0]+dp[i-1][1])%mod;
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][1];
            dp[i][3] = (dp[i-1][0]+dp[i-1][1])%mod;
        } else {
            dp[i][0] = (dp[i-2][0] + dp[i-1][3])%mod;
            dp[i][1] = ((dp[i-2][1] + dp[i-1][1])%mod+(dp[i-1][2] + dp[i-1][3])%mod)%mod;
        }
    }
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    calc();

    while(t--){
        int n;
        cin >> n;
        cout << dp[2*n][3] << "\n";
    }
    return 0;
}
