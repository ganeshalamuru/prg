#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = LLONG_MAX, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


void solve() {
	ll l,r;
    cin >> l >> r;
    auto numof = [&](ll x) {
        if (x<10)
            return 0ll;
        ll res = 0;
        string s = to_string(x);
        int n=s.size();
        for(int cds=2;cds<n;cds++) {
            for(int j=1;j<=9;j++)
                res+=powe(j,cds-1);
        }
        int md=s[0]-'0';
        for(int j=1;j<md;j++)
            res+=powe(j,n-1);
        for(int i=1;i<n;i++) {
            if (s[i]-'0'>=md) {
                res+=powe(md,n-i);
                return res;
            } else {
                res+=(s[i]-'0')*(powe(md,n-i-1));
            }
        }
        res++;
        return res;
    };
    cout << numof(r)-numof(l-1) << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
