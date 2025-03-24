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
	ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll sum = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum+=a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i=0;i<n;i++) {
        ll temp = sum - a[i];
        if (temp < x)
            continue;
        ll maxval = temp-x;
        auto itr = upper_bound(a.begin(), a.end(), maxval);
        int maxind = -1;
        if (itr==a.end()) {
            maxind = n-1;
        } else if (itr!=a.begin()){
            itr--;
            maxind = itr-a.begin();
        }
        ll minval = temp-y;
        auto itr2 = lower_bound(a.begin(), a.end(), minval);
        int minind=n;
        if (itr2!=a.end())
            minind=itr2-a.begin();
        if (minind<=maxind)
            ans+=maxind-minind+1;
    }
    for(int i=0;i<n;i++) {
        ll temp = sum - 2*a[i];
        if (temp>=x && temp<=y)
            ans--;
    }
    cout << ans/2 << "\n";
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
