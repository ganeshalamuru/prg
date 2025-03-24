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
    vector<pii> arr(n);
    map<int, vector<int>, greater<int>> freq;
    map<int, int> costnum;
    for(int i=0;i<n;i++)
        cin >> arr[i].S,freq[arr[i].S].push_back(i);
    int totcost = 0;
    for(int i=0;i<n;i++)
        cin >> arr[i].F, totcost+=arr[i].F, costnum[arr[i].S]+=arr[i].F;
    multiset<pii,greater<pii>> ss;
    for(int i=0;i<n;i++)
        ss.insert(arr[i]);
    int ans = INT_MAX;
    for(auto &pp:freq) {
        int costkeep = costnum[pp.F];
        int fq = pp.S.size();
        int keep = fq-1;
        auto itr= ss.begin();
        while (keep > 0 && itr!=ss.end()) {
            if (itr->S==pp.F) {
                itr++;
            } else {
                costkeep+=itr->F;
                itr++;
                keep--;
            }
        }
        ans = min(ans, totcost-costkeep);
        for(int j=0;j<pp.S.size();j++) {
            ss.erase(arr[pp.S[j]]);
        }
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
