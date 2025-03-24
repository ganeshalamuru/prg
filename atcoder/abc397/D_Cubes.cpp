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
    ll n;
    cin >> n;
    for(int d=1;1ll*d*d*d<=4*n;d++) {
        if (n%d!=0)
            continue;
        ll l=d+1,r=1e9l;
        while(l<r) {
            ll mid = l + (r-l+1)/2;
            if (3*mid*mid-3*mid*d+1ll*d*d<=n/d)
                l=mid;
            else
                r=mid-1;
        }
        if (3*l*l-3*l*d+1ll*d*d==n/d) {
            cout << l << " " << l-d << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
