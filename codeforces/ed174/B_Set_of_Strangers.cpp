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
    vector<vector<int>> grid(n,vector<int>(m));
    vector<int> color(n*m+1,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (color[grid[i][j]]==0)
                color[grid[i][j]]=1;
            int cnt = 0;
            for(auto &[dx,dy]:vector<pii>{{-1,0},{0,1},{1,0},{0,-1}}) {
                if (i+dx>=0 && i+dx<n && j+dy>=0 && j+dy<m) {
                    cnt+=(grid[i][j]==grid[i+dx][j+dy]);
                }
            }
            if (cnt>0)
                color[grid[i][j]]=2;
        }
    }
    int ans = 0;
    for(int i=1;i<=n*m;i++)
        ans+=color[i];
    cout << (ans - *max_element(color.begin(), color.end())) << "\n";
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
