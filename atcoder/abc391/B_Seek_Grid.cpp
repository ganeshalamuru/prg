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
	int m,n;
    cin >> n >> m;
    vector<string>s(n),t(m);
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<m;i++)
        cin >> t[i];
    for(int i=0;i<=n-m;i++) {
        for(int j=0;j<=n-m;j++) {
            bool found=true;;
            for(int x=0;x<m&&found;x++) {
                for(int y=0;y<m&&found;y++) {
                    if (s[i+x][j+y]!=t[x][y])
                        found=false;
                }
            }
            if (found) {
                cout << i+1 << " " << j+1 << "\n";
                return;
            }
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
