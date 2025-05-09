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
	int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int &num:a)
        cin >> num;
    for(int &num:b)
        cin >> num;
    vector<ll> psum(n,0);
    for(int i=0;i<n;i++) {
        if (a[i]>=b[i])
            continue;
        ll diff=b[i]-a[i];
        psum[0]-=diff;
        psum[i]+=diff;
        psum[i]+=diff;
        if (i+1<n) {
            psum[i+1]-=diff;
            psum[i+1]-=diff;
        }
    }
    ll sum = 0;
    for(int i=0;i<n;i++) {
        sum+=psum[i];
        if (1ll*a[i]+sum<1ll*b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
