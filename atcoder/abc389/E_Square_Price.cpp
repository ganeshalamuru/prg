#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = LLONG_MAX;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


void solve() {
    ll n,m;
    cin >> n >> m;
    vector<ll>p(n);
    for(int i=0;i<n;i++)
        cin >> p[i];
    auto possible = [&](ll x) {
        ll cost = 0;
        for(int i=0;i<n;i++) {
            ll cnt = (x+p[i])/(2*p[i]);
            if (cnt==0)
                continue;
            if (cnt <= INF/cnt && cnt*cnt <= INF/p[i] && cnt*cnt*p[i]<=INF-cost)
                cost+=cnt*cnt*p[i];
            else
                return false;
        }
        return cost<=m;
    };
    ll l=0,r=m;
    while(l<r) {
        ll mid = l+(r-l+1)/2;
        if (possible(mid)) {
            l=mid;
        } else {
            r=mid-1;
        }
    }
    ll tcnt=0,cost = 0;
    for(int i=0;i<n;i++) {
        ll cnt = (l+p[i])/(2*p[i]);
        tcnt+=cnt;
        cost+=cnt*cnt*p[i];
    }
    cout << tcnt + (m-cost)/(l+1) << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
