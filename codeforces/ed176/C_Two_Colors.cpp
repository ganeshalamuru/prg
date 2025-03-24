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
	int n,m;
    cin >> n >> m;
    vector<int> a(m);
    vector<ll> psum(m);
    for(int i=0;i<m;i++) {
        cin >> a[i];
        if (a[i]==n)
            a[i]--;
    }
    sort(a.begin(), a.end());
    psum[0] = a[0];
    for(int i=1;i<m;i++)
        psum[i] = psum[i-1]+a[i];
    ll ans = 0;
    for(int i=0;i<m;i++) {
        int req = n-a[i];
        auto itr = lower_bound(a.begin()+i+1, a.end(), req);
        if (itr!=a.end()) {
            int ind = (itr-(a.begin()+i+1));
            ll num = m-i-1-ind;
            ll ppsum = psum[m-1];
            ppsum-=psum[i+ind]; 
            ans+=2*(num*(a[i]+1)-(num*n-ppsum));
        }
    }
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