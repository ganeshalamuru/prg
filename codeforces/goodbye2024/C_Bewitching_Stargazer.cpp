#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}




pll lv(int n, int k) {
    if (n < k)
        return {0,0};
    pll rs, ans;
    if ((n&1)==1) {
        rs = lv((n-1)>>1, k);
        ans.F = ((n+1)>>1)*(rs.S+1) + 2*rs.F;
        ans.S = 1ll + 2ll*rs.S;
    } else {
        rs = lv(n>>1, k);
        ans.F = (n>>1)*(rs.S) + 2*rs.F;
        ans.S = 2*rs.S;
    }
    return ans;
}

void solve() {
	int n,k;
    cin >> n >> k;
    cout << lv(n,k).F << "\n";
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
