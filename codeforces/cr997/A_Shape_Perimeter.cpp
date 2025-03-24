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
    int sumr=0,sumt=0;
    vector<pii> arr(n);
    for(int i=0,x,y;i<n;i++) {
        cin >> x >> y;
        arr[i] = {x,y};
        sumr+=x;
        sumt+=y;
    }
    int maxr = m+sumr, maxt = m+sumt;
    cout << 2*(maxr-arr[0].F+ maxt-arr[0].S) << "\n";
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
