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



ll xorofkmod2iupton(ll n, ll i, ll k) {
    if (k>n)
        return 0;
    ll num = (n-k)/(1<<i);
    bitset<64> bsk(k),bsnum(num);
    ll ans = 0;
    for(int z=0;z<i;z++) {
        ans |= (bsk[z]&(bsnum[0]^1))<<z;
    }
    ans |= (bsnum[0]^bsnum[1])<<i;
    for(int z=i+1;z<61;z++) {
        ans |= (1ll*(bsnum[z-i]&(bsnum[0]^1)))<<z;
    }
    return ans;
}

ll xorupton(ll n) {
    bitset<64> bs(n);
    ll ans = 0;
    ans |= bs[0]^bs[1];
    for(int i=1;i<61;i++) {
        ans |= (1ll*(bs[i]&(bs[0]^1)))<<i;
    }
    return ans;
}

void solve() {
	ll l,r,i,k;
    cin >> l >> r >> i >> k;
    cout << ((xorupton(r)^xorupton(l-1))^(xorofkmod2iupton(r,i,k)^xorofkmod2iupton(l-1,i,k))) << "\n";
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
