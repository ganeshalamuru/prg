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
	int n,k;
    cin >> n >> k;
    vector<pair<int,int>> events(2*n);
    for(int j=0;j<2;j++)
        for(int i=0,num;i<n;i++)
            cin >> num, events[n*j + i]={num, j};
    sort(events.begin(), events.end());
    int i=0, negcnt = 0, buyers = n;
    ll ans = 0;
    while(i<2*n) {
        int price = events[i].F;
        if (negcnt <=k )
            ans = max(ans, 1ll*buyers*price);
        while(i<2*n && events[i].F==price) {
            if (events[i].S==0)
                negcnt++;
            else
                negcnt--,buyers--;
            i++;
        }
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
