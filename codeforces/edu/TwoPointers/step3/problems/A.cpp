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
    ll p;
    cin >> n >> p;
    vector<int>a(n);
    for(int &i:a)
        cin >> i;
    vector<ll> prefix(2*n,0);
    prefix[0]=a[0];
    for(int i=1;i<2*n;i++)
        prefix[i] = prefix[i-1] + a[i%n];
    int ind = -1;
    ll shortest = LLONG_MAX, total = prefix[n-1];
    
    for(int i=0;i<n;i++) {
        ll playlistlen = p/total;
        ll rem = p%total;
        rem += (i>=1?prefix[i-1]:0);
        auto itr = lower_bound(prefix.begin()+i, prefix.begin()+i+n, rem);

    }
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
