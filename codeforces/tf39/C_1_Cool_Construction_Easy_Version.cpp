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
    vector<vector<int>> grid(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            if ((i+j)%2==0) {
                grid[i][j]=2;
            } else {
                grid[i][j]=i+j;
            }
        }
        cout << "\n";
    }
    if (n%2==1) {
        grid[2][2]=10, grid[2][3]=15;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
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
