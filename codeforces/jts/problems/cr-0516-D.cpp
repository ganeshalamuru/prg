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


bool valid(int ni,int nj, vector<string> &brd) {
    int n = brd.size();
    int m = brd[0].size();
    if (ni>=0 && ni<n && nj>=0 && nj<m && brd[ni][nj]!='*')
        return true;
    return false;
}

void solve(){
	int n,m;
    cin >> n >> m;
    int r,c,x,y;
    cin >> r >> c >> x >> y;
    r--,c--;
    vector<string> brd(n);
    for(auto &str:brd)
        cin >> str;
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<pair<int,int>>>turns(n,vector<pair<int,int>>(m));
    int total = 0;
    queue<pair<int,int>> q;
    vis[r][c]=1;
    turns[r][c]={0,0};
    q.push({r,c});
    while(!q.empty()) {
        pair<int,int> cell = q.front();
        int i = cell.F, j = cell.S;
        pair<int,int>curTunrs=turns[i][j];
        q.pop();
        total++;
        if (valid(i+1,j,brd) && vis[i+1][j]==0) {
            vis[i+1][j]=1;
            q.push({i+1,j});
            turns[i+1][j]=curTunrs;
        }
        if (valid(i-1,j,brd) && vis[i-1][j]==0){
            vis[i-1][j]=1;
            q.push({i-1,j});
            turns[i-1][j]=curTunrs;
        }
        if (valid(i,j+1,brd) && curTunrs.S+1<=y && vis[i][j+1]==0) {
            vis[i][j+1]=1;
            q.push({i,j+1});
            turns[i][j+1]={curTunrs.F,curTunrs.S+1};
        }
        if (valid(i,j-1,brd) && curTunrs.F+1<=x && vis[i][j-1]==0) {
            vis[i][j-1]=1;
            q.push({i,j-1});
            turns[i][j-1]={curTunrs.F+1,curTunrs.S};
        }
    }
    cout << total << "\n";
}   




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
