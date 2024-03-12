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
	int n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(ll &i:a)
        cin >> i;
    for(ll &i:b)
        cin >> i;
    vector<ll> sa(n),sb(n);
    set<ll> setsb{b[n-1]};
    sa[n-1] = a[n-1], sb[n-1] = b[n-1];
    for(int i=n-2;i>=0;i--)
        sa[i] = sa[i+1] + a[i];
    for(int i=n-2;i>=0;i--)
        sb[i] = sb[i+1] + b[i],setsb.insert(sb[i]);
    ll maxans = LLONG_MIN;
    for(int i=0;i<n-1;i++)
        maxans = max(maxans, min(sa[i]-sb[0]+a[n-1], sa[i]-sb[i+1]-a[n-1]));
    maxans = max(maxans, 2*a[n-1] - sb[0]);
    cout << maxans << "\n";
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
