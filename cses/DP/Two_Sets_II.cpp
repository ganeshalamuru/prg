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
	int n;
    cin >> n;
    int summ = (n*(n+1))/2;
    if (summ%2==1) {
        cout << 0 << "\n";
        return;
    }
    vector<int>dp( summ/2 +1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=summ/2;j>=i;j--)
            dp[j]=(dp[j]+dp[j-i])%mod;
    }
    cout << (1ll*dp[summ/2]*powe(2,mod-2))%mod << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
