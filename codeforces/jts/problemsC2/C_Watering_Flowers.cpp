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


bool check(vector<vector<int>> &flowers, vector<int> &f1, ll r1sq, vector<int> &f2, ll r2sq) {
    for(int i=0;i<flowers.size();i++) {
        int x = flowers[i][0], y = flowers[i][1];
        ll dissqf1 = 1ll*(x-f1[0])*(x-f1[0]) + 1ll*(y-f1[1])*(y-f1[1]);
        ll dissqf2 = 1ll*(x-f2[0])*(x-f2[0]) + 1ll*(y-f2[1])*(y-f2[1]);
        if (dissqf1 > r1sq && dissqf2 > r2sq)
            return false;
    }
    return true;
}

void solve() {
	int n;
    vector<int> f1(2),f2(2);
    cin >> n >> f1[0] >> f1[1] >> f2[0] >> f2[1];
    vector<vector<int>> flowers(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin >> flowers[i][0] >> flowers[i][1];
    flowers.push_back({f1[0],f1[1]});
    ll ans = LLONG_MAX;
    for(int i=0;i<flowers.size();i++) {
        int x = flowers[i][0], y = flowers[i][1];
        ll rsq = 1ll*(x-f1[0])*(x-f1[0]) + 1ll*(y-f1[1])*(y-f1[1]);
        ll l=0,r=1e16;
        while(l<r) {
            ll mid = l + (r-l)/2;
            if (check(flowers, f1, rsq, f2, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = min(ans, rsq + l); 
    }
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
