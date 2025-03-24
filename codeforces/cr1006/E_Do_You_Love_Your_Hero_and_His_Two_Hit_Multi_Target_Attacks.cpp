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



vector<int> arr(501,0);

void solve() {
	int k;
    cin >> k;
    vector<pii> ans;
    int x=0,y=0;
    while(k>0) {
        auto itr = lower_bound(arr.begin(), arr.end(), k);
        if ((*itr)>k)
            itr--;
        int pointstoplace = (itr-arr.begin());
        while(pointstoplace--) {
            ans.push_back({x,y});
            x++;
        }
        k-=(*itr);
        y++;
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) {
        cout << ans[i].F << " " << ans[i].S << "\n"; 
    }
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    int sum = 0;
    for(int i=1;i<501;i++) {
        sum+=(i-1);
        arr[i]=sum;
    }
    while(t--){
    	solve();
    }
    return 0;
}
