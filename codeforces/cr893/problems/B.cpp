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
	ll n,m,d;
    cin >> n >> m >> d;
    vector<ll> cs(m);
    for (ll &i : cs)
        cin >> i;
    ll minCookies = INT_MAX, count = 0;
    vector<ll> cprefix(m),csuffix(m);
    cprefix[0] = 1 + (cs[0] - 1 - 1) / (d) + (cs[0]!=1);
    for (int i = 1; i < cprefix.size(); i++)
        cprefix[i] = cprefix[i-1] + (cs[i]-1-cs[i-1])/d + 1;
    csuffix[m-1] = 1 + (n-cs[m-1]) / d;
    for (int i = m-2; i >=0 ; i--) {
        csuffix[i] = 1 + (cs[i+1]-1-cs[i]) / d + csuffix[i+1];
    }
    for (int i = 0; i<m;i++) {
        if ( i==0) {
            ll totalCookies = csuffix[i+1];
            totalCookies += 1 + (cs[i+1] - 1 -1) / d;
            if (totalCookies < minCookies) {
                minCookies = totalCookies;
                count = 1;
            } else if (minCookies == totalCookies)
                count++;
            continue;
        }
        if (i == m - 1) {
            ll totalc = cprefix[i-1];
            totalc += (n - cs[i-1]) / d;
            if (totalc < minCookies) {
                minCookies = totalc;
                count = 1;
            } else if (totalc == minCookies)
                count++;
            continue;
        }
        ll totalc = cprefix[i-1] + csuffix[i+1] + (cs[i+1]-1 - cs[i-1]) / d;
        if (totalc < minCookies) {
            minCookies = totalc;
            count = 1;
        } else if (totalc == minCookies)
            count++;
    }
    cout << minCookies << " " << count << "\n";

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
