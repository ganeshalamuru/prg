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



ll calcpoints(vector<pair<ll,ll>> segments) {
    if (segments.empty())
        return 0;
    sort(segments.begin(), segments.end());
    vector<pair<ll,ll>> merged{segments[0]};
    for(int i=1;i<segments.size();i++) {
        if (merged.back().S<segments[i].F) {
            merged.push_back(segments[i]);
        } else {
            merged.back().S = max(merged.back().S, segments[i].S);
        }
    }
    ll numpoints = 0;
    for(int i=0;i<merged.size();i++) {
        numpoints+=merged[i].S-merged[i].F+1;
    }
    return numpoints;
} 


void solve() {
	int n,m;
    cin >> n >> m;
    vector<pii> arr(n);
    int maxr = INT_MIN;
    for(int i=0;i<n;i++)
        cin >> arr[i].F;
    for(int i=0;i<n;i++)
        cin >> arr[i].S,maxr=max(maxr, arr[i].S);
    ll ans = 0;
    vector<vector<pair<ll,ll>>> segments(maxr+1);
    for(int i=0;i<n;i++) {
        for(int j=0;j<=arr[i].S;j++) {
            ll sq = sqrtl(1ll*arr[i].S*arr[i].S - 1ll*j*j);
            segments[j].push_back({arr[i].F-sq, arr[i].F+sq});
        }
    }
    ans += calcpoints(segments[0]);
    for(int i=1;i<segments.size();i++) {
        ans += 2*calcpoints(segments[i]);
    }
    cout << ans << "\n";
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
