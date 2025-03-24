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
    vector<vector<int>> events;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        events.push_back({a,0,i});
        events.push_back({b,1,i});
    }
    sort(events.begin(), events.end());
    int i=0;
    int maxr = 0;
    vector<int> ans(n);
    set<int> ss;
    while(i<events.size()) {
        if (events[i][1]==0) {
            if (ss.empty()) {
                maxr++;
                ans[events[i][2]]=maxr;   
            } else {
                int roomavai = *ss.begin();
                ans[events[i][2]]=roomavai;
                ss.erase(roomavai);
            }
        } else {
            ss.insert(ans[events[i][2]]);
        }
        i++;
    }
    cout << maxr << "\n";
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";


}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
