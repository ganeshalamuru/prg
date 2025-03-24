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

int sumofd(int x) {
    int ans = 0;
    while(x>0)
        ans += x%10, x/=10;
    return ans;
}

void solve() {
	ll n;
    cin >> n;
    for(int sod=1;sod<=81;sod++) {
        int l=1,r=1e9-1;
        while(l<r) {
            int mid = l + (r-l)/2;
            ll val = 1ll*mid*mid + 1ll*sod*mid;
            if (val == n) {
                l = mid, r= mid;
                break;
            } else if (val < n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (1ll*l*l + 1ll*sod*l == n && sumofd(l)==sod) {
            cout << l << "\n";
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
