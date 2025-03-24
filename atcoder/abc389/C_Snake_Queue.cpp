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
	int q;
    cin >> q;
    vector<pair<ll,ll>> qq(q+1);
    int h=0,t=0;
    while(q--) {
        int type,l,k;
        cin >> type;
        if (type==1) {
            cin >> l;
            if (h==-1) {
                qq[0]={0,l};
                h=0,t=1;
            } else {
                qq[t]={qq[t-1].F+qq[t-1].S,l};
                t++;
            }
        } else if (type==2) {
            h++;
        } else if (type==3) {
            cin >> k;
            k--;
            cout << qq[h+k].F-qq[h].F << "\n";
        }
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
