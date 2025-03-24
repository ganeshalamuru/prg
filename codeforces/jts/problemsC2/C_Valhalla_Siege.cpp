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
	int n,q;
    cin >> n >> q;
    vector<ll> arr(n), numarrows(q);
    for(auto &num:arr)
        cin >> num;
    for(auto &num:numarrows)
        cin >> num;
    vector<ll> psum(n);
    psum[0] = arr[0];
    for(int i=1;i<n;i++)
        psum[i] = psum[i-1] + arr[i];
    ll arrowsused = 0,i=0;;
    while(i<numarrows.size()) {
        arrowsused += numarrows[i];
        auto itr = upper_bound(psum.begin(), psum.end(), arrowsused);
        cout << ((n - (itr-psum.begin())) -1 + n)%n + 1 << "\n";
        if (itr == psum.end())
            arrowsused = 0;
        
        i++;
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
