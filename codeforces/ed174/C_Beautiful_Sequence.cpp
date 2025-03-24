#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 998244353, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


int madd(ll a, ll b) {
    a%=mod, b%=mod;
    return (a+b)%mod;
}

void solve() {
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(4,INT_MIN));
    if (a[0]==1)
        dp[0][1]=1;
    for(int i=1;i<n;i++) {
        if (a[i]==1) {
            if (dp[i-1][1]!=INT_MIN)
                dp[i][1] = madd(1,dp[i-1][1]);
            else
                dp[i][1] = 1;
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
        } else if (a[i]==2) {
            if (dp[i-1][1]!=INT_MIN) {
                if (dp[i-1][2]!=INT_MIN)
                    dp[i][2] = madd(dp[i-1][1], madd(dp[i-1][2], dp[i-1][2]));
                else
                    dp[i][2] = dp[i-1][1];
            }
            dp[i][1]=dp[i-1][1];
            dp[i][3]=dp[i-1][3];
        } else {
            if (dp[i-1][2]!=INT_MIN) {
                if (dp[i-1][3]!=INT_MIN)
                    dp[i][3] = madd(dp[i-1][2], dp[i-1][3]);
                else
                    dp[i][3]=dp[i-1][2];
            }
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
        }
    }
    if (dp[n-1][3]==INT_MIN)
        cout << 0 << "\n";
    else
        cout << dp[n-1][3] << "\n";
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
