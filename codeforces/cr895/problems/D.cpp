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
	ll n,x,y;
    cin >> n >> x >> y;
    ll numx = n / x, numy = n / y;
    ll lcm = (x*y) / (__gcd(x,y));
    ll numlcm = n / lcm;
    ll post = numx - numlcm;
    ll score = (n*(post)) - ((post-1)*(post))/2;
    ll negt = numy - numlcm;
    score -= (negt*(negt+1))/2;
    cout << score << "\n";
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
