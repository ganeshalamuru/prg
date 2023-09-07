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

int n,m;
vector<string> brd;
vector<vector<int>> vis;

void dfs(int i, int j, int color) {
    if (vis[i][j] != -1) {
        return;
    }
    vis[i][j] = color;
    for(int z=j+1;z<m;z++) {
        if(brd[i][z] != '.') {
            dfs(i,z, color^1);
            break;
        }
    }
    for(int z=i+1;z<n;z++) {
        if (brd[z][j] != '.') {
            dfs(z,j,color^1);
            break;
        }
    }
    for(int z=j-1;z>=0;z--) {
        if (brd[i][z] != '.') {
            dfs(i,z,color^1);
            break;
        }
    }
    for(int z=i-1;z>=0;z--) {
        if (brd[z][j] != '.') {
            dfs(z,j,color^1);
            break;
        }
    }
}


void solve(){
    cin >> n >> m;
    brd = vector<string>(n);
    vis = vector<vector<int>>(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
        cin >> brd[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if (brd[i][j]!='.' && vis[i][j]==-1)
                dfs(i,j,0);
    bool monchrome = true;
    for(int i=0;i<n && monchrome;i++) {
        for(int j=0;j<m && monchrome;j++) {
            if (brd[i][j] == '.')
                continue;
            if (brd[i][j] == 'L' && vis[i][j]==vis[i][j+1]) {
                monchrome = false;
            } else if (brd[i][j] == 'R' && vis[i][j]==vis[i][j-1]){
                monchrome = false;
            } else if (brd[i][j] == 'U' && vis[i][j]==vis[i+1][j]) {
                monchrome = false;
            } else if (brd[i][j] == 'D' && vis[i][j]==vis[i-1][j]) {
                monchrome = false;
            }
        }
    }
    bool numwbeq = true;
    for(int i=0;i<n && numwbeq;i++) {
        int b=0,w=0;
        for(int j=0;j<m && numwbeq;j++)
            if (vis[i][j]==0)
                b++;
            else if(vis[i][j]==1)
                w++;
        if (b!=w)
            numwbeq = false;
    }
    for(int j=0;j<m && numwbeq;j++) {
        int b=0,w=0;
        for(int i=0;i<n && numwbeq;i++)
            if (vis[i][j]==0)
                b++;
            else if(vis[i][j]==1)
                w++;
        if (b!=w)
            numwbeq = false;
    }
    if (!numwbeq || !monchrome) {
        cout << -1 << "\n";
        return;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (brd[i][j] == '.')
                cout << ".";
            else
                cout << (vis[i][j] ? 'W':'B');
        }
        cout << "\n";
    }
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
