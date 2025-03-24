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
    multiset<int>h;
    for(int i=0,x;i<n;i++)
        cin >> x,h.insert(x);
    vector<int> c(m);
    for(int i=0;i<m;i++)
        cin >> c[i];
    vector<int> ans(m);
    for(int i=0;i<m;i++) {
        if (h.empty()) {
            ans[i]=-1;
            continue;
        }
        auto itr = h.upper_bound(c[i]);
        if (itr == h.begin()) {
            ans[i]=-1;
            continue;
        } else {
            itr--;
        }
        ans[i]=*itr;
        h.erase(itr);
    }
    for(int i=0;i<m;i++)
        cout << ans[i] << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
