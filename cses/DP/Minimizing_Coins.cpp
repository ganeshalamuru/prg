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
    vector<int> c(n);
    for(int i=0;i<n;i++)
        cin >> c[i];
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++) {
        for(int j=0;j<n;j++) {
            if (i-c[j]>=0 && dp[i-c[j]]!=INT_MAX)
                dp[i]=min(dp[i], 1+dp[i-c[j]]);
        }
    }
    if (dp[x]==INT_MAX)
        cout << -1 << "\n";
    else
        cout << dp[x] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
