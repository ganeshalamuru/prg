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
	int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        for(int j=0,num;j<m;j++)
            cin >> num;
    cout << m*(m-1)/2 << "\n";
    if (k==0) {
        for(int i=1;i<=m;i++) {
            for (int j=i+1;j<=m;j++) {
                cout << i << " " << j << "\n";
            }
        }
    } else {
        for(int i=m;i>=1;i--) {
            for(int j=i-1;j>=1;j--) {
                cout << i << " " << j << "\n";
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
