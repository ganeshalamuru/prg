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
	int n,m;
    cin >> n >> m;
    int gcdd = __gcd(n,m);
    n /= gcdd, m /= gcdd;
    if ((m & (m-1)) != 0) {
        cout << -1 << "\n";
        return;
    }
    int rem = n%m;
    ll mincuts = 0;
    int mpow = 0;
    while((1<<mpow) != m) mpow++;
    int npow = 0, tempn = rem;
    while(tempn > 0) {
        if (tempn&1) {
            mincuts += 1ll*gcdd*(1<<npow)*((1<<(mpow-npow)) - 1);
        }
        tempn>>=1;
        npow++;
    }
    cout << mincuts << "\n";
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
