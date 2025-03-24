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
    vector<string>gg(2);
    cin >> gg[0] >> gg[1];
    if (n<3) {
        cout << 0 << "\n";
        return;
    }
    int ans = 0;
    for(int i=1;i<n;i++) {
        for(int j=0,flip=0;j<2;j++,flip^=1) {
            if (gg[flip][i]=='.'&&gg[flip][i-1]=='.' && gg[flip][i+1]=='.') {
                if (gg[flip^1][i]=='.'&&gg[flip^1][i-1]=='x'&&gg[flip^1][i+1]=='x')
                    ans++;
            }

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
