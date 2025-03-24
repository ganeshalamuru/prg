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




void solve(){
	int n;
    cin >> n;
    vector<string> grid(2);
    for(auto &str:grid)
        cin >> str;
    vector<vector<int>> vis(2,vector<int>(n,0));
    vis[0][0] = 1;
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<pair<int,int>> dif{{0,-1},{0,1},{-1,0},{1,0}};
    while(!q.empty()) {
        auto cell = q.front();
        int curx = cell.first;
        int cury = cell.second;
        q.pop();
        for(int i=0;i<4;i++) {
            int newx = curx+dif[i].first, newy = cury+dif[i].second;
            if (newx>=0 && newx<2 && newy>=0 && newy<n) {
                int finx = newx;
                int finy = newy;
                if (grid[newx][newy] == '<')
                    finy--;
                else
                    finy++;
                if (vis[finx][finy] == 0) {
                    vis[finx][finy] = 1;
                    q.push({finx,finy});
                }
            }
        }
    }
    if (vis[1][n-1] == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}   




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
