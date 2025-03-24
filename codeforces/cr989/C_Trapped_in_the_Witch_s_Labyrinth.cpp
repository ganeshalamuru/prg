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


bool validcell(pair<int,int> &cell, int n, int m) {
    if (cell.F>=0 && cell.F<n && cell.S>=0 && cell.S<m )
        return true;
    return false;
}
map<char, pair<int,int>> mp{{'U',{-1,0}},{'L',{0,-1}},{'R',{0,1}},{'D',{1,0}}};
void dfs(pair<int,int> cell,vector<vector<int>> &vis,vector<string> &grid) {
    vis[cell.F][cell.S] = 1;
    int n = grid.size(), m = grid[0].size();
    for(auto &pp:mp) {
        pair<int,int> ncell = {cell.F+pp.S.F, cell.S+pp.S.S};
        if (!validcell(ncell,n,m) || grid[ncell.F][ncell.S]=='?' || vis[ncell.F][ncell.S]==1 )
            continue;
        auto &dir = mp[grid[ncell.F][ncell.S]];
        pair<int,int> travelcell = {ncell.F+dir.F,ncell.S+dir.S};
        if (validcell(ncell,n,m) && travelcell == cell) {
            dfs(ncell, vis, grid);
        }
    }
}
void solve() {
	int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
        cin >> grid[i];
    vector<pair<int,int>> qq;
    vector<vector<int>> vis(n,vector<int>(m,0));
    if (grid[0][0] == 'U' || grid[0][0]=='L')
        qq.push_back({0,0});
    if (grid[0][m-1] == 'U' || grid[0][m-1]=='R')
        qq.push_back({0,m-1});
    if (grid[n-1][0] == 'D' || grid[n-1][0]=='L')
        qq.push_back({n-1,0});
    if (grid[n-1][m-1]=='D' || grid[n-1][m-1]=='R')
        qq.push_back({n-1,m-1});
    for(int j=1;j<m-1;j++) {
        if (grid[0][j]=='U')
            qq.push_back({0,j});
        if (grid[n-1][j]=='D')
            qq.push_back({n-1,j});
    }
    for(int i=1;i<n-1;i++) {
        if (grid[i][0]=='L')
            qq.push_back({i,0});
        if (grid[i][m-1]=='R')
            qq.push_back({i,m-1});
    }
    for(int i=0;i<qq.size();i++) {
        dfs(qq[i],vis,grid);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (grid[i][j]!='?')
                continue;
            bool outposafter = true;
            for(auto &pp:mp) {
                pair<int,int> ncell = {i+pp.S.F, j+pp.S.S};
                if (validcell(ncell,n,m) && vis[ncell.F][ncell.S]==0) {
                    outposafter = false;
                    break;
                }
            }
            vis[i][j]= outposafter;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            ans += (vis[i][j]==0);
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
