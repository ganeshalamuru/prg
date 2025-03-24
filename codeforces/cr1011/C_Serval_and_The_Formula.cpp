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
	ll x,y;
    cin >> x >> y;
    if (x==y) {
        cout << -1 << "\n";
        return;
    }
    if (x+y == (x^y)) {
        cout << 0 << "\n";
        return;
    }
    if (x>y)
        swap(x,y);
    bitset<32>bsy(y);
    int j=31;
    ll ans = 0;
    while(j>=0 && bsy[j]==0)
        j--;
    for(int z=j;z>=0;z--) {
        if (bsy[z]==0)
            ans|=(1<<z);
    }
    ans++;
    cout << ans << "\n";

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
