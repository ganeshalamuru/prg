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
    string str = to_string(n);
    int m = str.size();
    int ans = INT_MAX;
    ll nines = 9;
    for(int i=1;i<=m;i++,nines=nines*10+9) {
        ll num = n;
        int ops = 0;
        str = to_string(num);
        while(str.find('7')==string::npos) {
            num+=nines;
            ops++;
            str = to_string(num);
        }
        ans = min(ans, ops);
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
