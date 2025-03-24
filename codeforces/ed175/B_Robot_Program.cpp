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
	ll n,x,k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    ll cur = x,t0=0,ans=0,t1=0;
    for(int i=0;i<n&&t0<k;i++) {
        if (s[i]=='L')
            cur--;
        else
            cur++;
        t0++;
        if (cur==0)
            break;
    }
    if (cur!=0) {
        cout << 0 << "\n";
        return;
    }
    k-=t0;
    ans++;
    for(int i=0;i<n&&t1<k;i++) {
        if (s[i]=='L')
            cur--;
        else
            cur++;
        t1++;
        if (cur==0)
            break;
    }
    if (cur==0 && t1>0)
        ans+=k/t1;
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
