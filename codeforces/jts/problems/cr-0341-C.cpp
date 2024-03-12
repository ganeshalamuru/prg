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
	int n,p;
    cin >> n >> p;
    vector<ll> t(n);
    vector<ll> ndivp(n);
    for(int l,r,i=0;i<n;i++) {
        cin >> l >> r;
        int numlm1 = (l-1) / p;
        int numr = r / p;
        t[i] = (r - l + 1);
        ndivp[i] = t[i] - (numr - numlm1);
        
    }
    ld ev = 0.0;
    for(int i=0;i<n-1;i++)
        ev += ((t[i]*t[i+1] - ndivp[i]*ndivp[i+1]) / (1.0l*t[i]*t[i+1]));
    ev += ((t[n-1]*t[0] - ndivp[n-1]*ndivp[0]) / (1.0l*t[n-1]*t[0]));
    cout << fixed << setprecision(7)<<2000.0*ev << "\n";
}


signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
