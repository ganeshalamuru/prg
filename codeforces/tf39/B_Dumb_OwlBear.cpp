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
	ll n;
    cin >> n;
    vector<int> arr(n);
    ll total = 0, total2;
    for(int &num:arr)
        cin >> num, total+=num;
    vector<ll> arr2(n,total),psum(n,0);
    total2=(n-1)*total;
    arr2[0]-=arr[0];
    psum[0]=arr2[0];
    for(int i=1;i<n;i++)
        arr2[i]-=arr[i],psum[i]=psum[i-1]+arr2[i];
    int q;
    cin >> q;
    while(q--) {
        ll h;
        cin >> h;
        ll mint = 1ll*(h/total2)*n;
        h = h%total2;
        if (h!=0)
            mint+=(lower_bound(psum.begin(), psum.end(), h)-psum.begin())+1;
        cout << mint << "\n";
    }
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
