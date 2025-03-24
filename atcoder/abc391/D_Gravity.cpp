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
	int n,w;
    cin >> n >> w;
    vector<vector<pii>> blocks(w);
    for(int i=0,x,y;i<n;i++) {
        cin >> x >> y;
        x--,y--;
        blocks[x].push_back({y,i});
    }
    vector<int> tt(n,INT_MAX);
    for(int i=0;i<w;i++)
        sort(blocks[i].rbegin(), blocks[i].rend());
    int timee = 0;
    while(true) {
        int cnt = 0;
        for(int i=0;i<w;i++) {
            if (blocks[i].empty())
                break;
            cnt++;
            if (blocks[i].back().F>timee)
                timee=blocks[i].back().F;
        };
        if (cnt!=w)
            break;
        for(int i=0;i<w;i++)
            tt[blocks[i].back().S]=timee,blocks[i].pop_back();
        timee++;
        
    }
    int q;
    cin >> q;
    while(q--) {
        int t,a;
        cin >> t >> a;
        a--;
        if (t<=tt[a])
            cout << "Yes\n";
        else
            cout << "No\n";
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
