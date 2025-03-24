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
	ll n,k;
    cin >> n >> k;
    vector<ll> h(n);
    for(int i=0;i<n;i++)
        cin >> h[i];
    sort(h.rbegin(), h.rend());
    ll moves = 0, sum = h[0];
    for(int i=1;i<n;i++) {
        if (sum-i*(h[i])>=k) {
            ll abovprev = sum - i*h[i-1];
            ll diff = k - abovprev;
            ll q = diff/i;
            moves++;
            sum = i*(h[i-1]-q);
            ll blocks = sum - i*h[i];
            ll clos = i * (k/i);
            moves += blocks/clos;
            sum = i*h[i] + blocks%clos;
        }
        sum+=h[i];
    }
    cout << moves + ((n)*(h[n-1]) != sum)<< "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
