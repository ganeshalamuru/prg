#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
        cin >> grid[i];
    vector<vector<int>> vis(n,vector<int>(m,0));
    function<void(int,int)> dfs = [&](int i,int j) {
        vis[i][j]=1;
        for(auto &[dx,dy]:vector<pii>{{-1,0},{0,1},{1,0},{0,-1}}) {
            int nx=i+dx,ny=j+dy;
            if (nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] || grid[nx][ny]=='#')
                continue;
            dfs(nx,ny);
        }
    };
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (vis[i][j]!=0 || grid[i][j]=='#')
                continue;
            dfs(i,j);
            cnt++;
        }
    }
    cout << cnt << "\n";

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
