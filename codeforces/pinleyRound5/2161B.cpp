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



void solve(vector<string> grid) {
	int n=int(grid.size());
    // cin >> n;
    // vector<string> grid(n);
    // for(int i=0;i<n;i++) {
    //     cin >> grid[i];
    //     cout << grid[i] << "\n";
    // }
    for(int i=0;i<n;i++) {
        for(int j=2;j<n;j++) {
            if (grid[i][j]=='#' && grid[i][j]==grid[i][j-1] && grid[i][j-1]==grid[i][j-2]) {
                cout << "NO\n";
                return;
            }
        }
    }
    for(int i=2;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (grid[i][j]=='#' && grid[i][j]==grid[i-1][j] && grid[i-1][j]==grid[i-2][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    vector<vector<int>> vis(n,vector<int>(n,0));
    auto dfs = [&](this auto self,int x,int y)->void {
        vis[x][y]=1;
        for(auto &[dx,dy]:{pii{-1,0},{0,1},{1,0},{0,-1}}) {
            int nx=x+dx,ny=y+dy;
            if (nx<0 || nx>=n || ny<0 || ny>=n)
                continue;
            if (vis[nx][ny]!=0 || grid[nx][ny]=='.')
                continue;
            self(nx,ny);    
        }
    };
    int numcomp=0,numblack = 0;;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (grid[i][j]=='#')
                numblack++;
            if (grid[i][j]=='.' || vis[i][j]!=0)
                continue;
            dfs(i,j);
            numcomp++;
        }
    }
    if (numcomp<2) {
        cout << "YES\n";
        return;
    }
    int initx=-1,inity=-1;
    for(int i=0;i<n && initx==-1;i++) {
        for(int j=0;j<n;j++) {
            if (grid[i][j]=='#') {
                initx=i,inity=j;
                // LD,DL,RD,DR
                for(auto &[dx,dy,st]:{array<int,3>{1,-1,0},{1,-1,1},{1,1,0},{1,1,1}}) {
                    int tx=initx,ty=inity,nb =0,vorh=st;
                    while(tx>=0 && tx<n && ty>=0 && ty<n) {
                        if (grid[tx][ty]=='#')
                            nb++;
                        if (vorh==0) {
                            ty+=dy;
                        } else {
                            tx+=dx;
                        }
                        vorh^=1;
                    }
                    if (nb==numblack) {
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }

    cout << "NO\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 2);  // distribution in range [1, 6]
    // std::cout << dist6(rng) << std::endl;
    int n=4;
    while(t--) {
        cin >> n;
        vector<string> grid(n,string(n,'.'));
        for(int i=0;i<n;i++) {
            cin >> grid[i];
            // for(int j=0;j<n;j++) {
            //     if (dist6(rng)==2)
            //         grid[i][j]='#';
            // }
            // cout << grid[i] << "\n";
        }
    	solve(grid);
    }
    
    return 0;
}