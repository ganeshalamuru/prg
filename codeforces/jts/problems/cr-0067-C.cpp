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
	int a, b;
    cin >> a >> b;
    int gcd = __gcd(a,b);
    set<int> dgcd;
    for(int j=1; j*j <= gcd;j++) {
        if (gcd%j == 0) {
            dgcd.insert(j);
            dgcd.insert(gcd/j);
        }
    }
    int n;
    cin >> n;
    while(n--) {
        int l,h;
        cin >> l >> h;
        auto itr = dgcd.lower_bound(h);
        int divisor;
        if (itr == dgcd.end())
            divisor = (*dgcd.rbegin());
        else if (*itr == h)
            divisor = h;
        else 
            itr--,divisor = *itr;

        if (divisor>=l)
            cout << divisor << "\n";
        else    
            cout << -1 << "\n";
    }
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
