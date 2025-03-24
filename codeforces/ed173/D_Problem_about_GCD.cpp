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
	ll l,r,G;
    cin >> l >> r >> G;
    ll firstmultiple = l/G + ((l%G==0)?0:1);
    ll lastmutliple = r/G;
    if (firstmultiple>lastmutliple) {
        cout << -1 << " " << -1 << "\n";
        return;
    }
    if (firstmultiple==lastmutliple) {
        if (firstmultiple==1) {
            cout << G << " " << G << "\n";
            return;
        } else {
            cout << -1 << " " << -1 << "\n";
        }
    } else {
        if (__gcd(firstmultiple,lastmutliple)==1) {
            cout << firstmultiple*G << " " << lastmutliple*G << "\n";
        } else (__gcd(firstmultiple, lastmutliple-1) == 1) {
            cout << firstmultiple*G << " " << (lastmutliple-1)*G << "\n";
        } else if (__gcd(firstmultiple+1, lastmutliple) == 1) {
            cout << (firstmultiple+1)*G << " " << lastmutliple*G << "\n";
        }
    }

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
