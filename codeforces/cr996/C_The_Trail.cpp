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
	int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<ll>> grid(n,vector<ll>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            cin >> grid[i][j];
    }
    vector<ll> rowsum(n),colsum(m);
    for(int i=0;i<n;i++) {
        rowsum[i]+=grid[i][0];
        for(int j=1;j<m;j++)
            rowsum[i]+=grid[i][j];
    }
    for(int j=0;j<m;j++) {
        colsum[j]+=grid[0][j];
        for(int i=1;i<n;i++)
            colsum[j]+=grid[i][j];
    }
    int i=0,j=0,z=0;
    while(z<s.size()) {
        if (s[z]=='D') {
            grid[i][j] = -rowsum[i];
            colsum[j]+= grid[i][j];
            i++;
        } else {
            grid[i][j] = -colsum[j];
            rowsum[i]+=grid[i][j];
            j++;
        }
        z++;
    }
    grid[n-1][m-1] = -rowsum[n-1];
    for(auto &row:grid) {
        for(auto &cell:row) {
            cout << cell << " ";
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
