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
	ll k,b,n,t;
    cin >> k >> b >> n >> t;
    if (k==1) {
        ll num = n*b+1-t;
        if (num<=0)
            cout << 0 << "\n";
        else
            cout <<  num/b + ((num%b)!=0) << "\n";
        return;
    }
    ll pow = 0,base=1;
    // finding log_k ((t*(k-1)+b)/(k-1+b))
    while(base<=(LLONG_MAX/(k-1+b)) && base*(k-1+b)<=t*(k-1)+b) {
        if (base > (LLONG_MAX/k)) {
            pow++;
            break;
        }
        base*=k;
        pow++;
    }
    cout << max(0ll,n-pow+1) << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
