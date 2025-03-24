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
    vector<int>a(n);
    int maxval = INT_MIN;
    for(int i=0;i<n;i++)
        cin >> a[i],maxval = max(maxval, a[i]);
    vector<vector<int>> adj(n);
    for(int i=1,p;i<n;i++) {
        cin >> p;
        p--;
        adj[p].push_back(i);
    }
    function<bool(int,ll)> possible = [&](int u, ll inc) {
        if (adj[u].size()==0)
            return 1ll*a[u]>=inc;
        for(int &v:adj[u]) {
            ll newinc = inc+max(0ll,inc-1ll*a[v]);
            if (newinc>1ll*maxval || !possible(v,newinc))
                return false;
        }
        return true;
    };

    int l = 0,r=maxval;
    while(l<r) {
        int mid = l + (r-l+1)/2;
        if (possible(0,mid)) {
            l=mid;
        } else {
            r=mid-1;
        }
    }
    cout << a[0]+l << "\n";
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
