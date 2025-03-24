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
	ll R;
    cin >> R;
    ll ans = 0;
    for(ll i=0;i<=R;i++) {
        ll l=0,r=R;
        while(l<r) {
            ll mid = l+(r-l+1)/2;
            if ((2*mid+1)*(2*mid+1)+(2*i+1)*(2*i+1)<=4*R*R) {
                l=mid;
            } else {
                r=mid-1;
            }
        }
        if ((2*l+1)*(2*l+1)+(2*i+1)*(2*i+1)<=4*R*R) {
            if (i==0)
                ans+=2*l+1;
            else
                ans+=4*l+2;
        }
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
