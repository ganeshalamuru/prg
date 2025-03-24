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
	ll t,w,b;
    cin >> t >> w >> b;
    ll gcdd = __gcd(w,b) ;
    ll temp1 = b/gcdd, quo = t/temp1;
    ll p,q=t;
    if (quo < w) {
        p = min(t,min(w,b)-1);
    } else {
        ll lcm = (b/gcdd)*w;
        p = (t/lcm)*(min(w,b)-lcm) + min(t, (t/lcm)*lcm + min(w,b)-1);
    }
    ll gcd2 = __gcd(p,q);
    p/=gcd2, q/=gcd2;
    cout << p << "/" << q << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
