#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	int h,w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i=0;i<h;i++) {
        cin >> grid[i];
    }
    vector<vector<pii>> cadj(26);
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if (isalpha(grid[i][j]))
                cadj[grid[i][j]-'a'].push_back({i,j});
        }
    }
    vector<vector<int>> vis(h,vector<int>(w,-1));
    vector<int> warpsmallvis(26,-1);
    vis[0][0]=0;
    queue<pii> q;
    q.push({0,0});
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for(auto [nx,ny]:{pii{x-1,y},{x,y+1},{x+1,y},{x,y-1}}) {
            if (nx<0 || nx>=h || ny<0 || ny>=w)
                continue;
            if (vis[nx][ny]!=-1 || grid[nx][ny]=='#')
                continue;    
            vis[nx][ny]= vis[x][y]+1;
            q.push({nx,ny});
        }
        if (isalpha(grid[x][y]) && warpsmallvis[grid[x][y]-'a']==-1) {
            warpsmallvis[grid[x][y]-'a']=vis[x][y];
            for(auto [nx,ny]:cadj[grid[x][y]-'a']) {
                if (vis[nx][ny]!=-1)
                    continue;
                vis[nx][ny]=vis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    cout << vis[h-1][w-1] << "\n";


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
