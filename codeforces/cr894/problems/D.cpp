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




void solve(){
	ll n;
    cin >> n;
    ll l = 1, r = 2e9;
    while(l<r) {
        ll mid = l + (r-l + 1) / 2;
        ll val = (mid*(mid - 1)) / 2;
        if (n < val) {
            r = mid - 1;
        } else {
            l=mid;
        }
    }
    cout << l + (n - (l*(l-1))/2)<< "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
