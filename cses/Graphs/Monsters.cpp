#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

void solve() {
	int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto &str:grid)
        cin >> str;
    vector<pii> monsters,player;
    for(int i=0;auto &str:grid) {
        for(int j=0;char ch:str) {
            if (ch=='M') {
                monsters.push_back({i,j});
            } else if (ch=='A') {
                player.push_back({i,j});
            }
            j++;
        }
        i++;
    }
    auto bfs=[&](vector<pii>& starts) {
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        queue<pii> q;
        for(auto &cell:starts)
            q.push(cell),dis[cell.F][cell.S]=0;
        while(!q.empty()) {
            auto &[x,y] = q.front();
            for(auto &[dx,dy]:{pii{-1,0},{0,1},{1,0},{0,-1}}) {
                int nx=x+dx,ny=y+dy;
                if (nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]=='#'||dis[nx][ny]!=INT_MAX) {
                    continue;
                }
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
            q.pop();
        }
        return dis;
    };
    vector<vector<int>> dis = bfs(player), mdis=bfs(monsters);
    pii eexit = {-1,-1};
    for(int i=0;i<n;i++) {
        if (grid[i][0]!='#'&& dis[i][0]<mdis[i][0]) {
            eexit={i,0};
            break;
        }
        if (grid[i][m-1]!='#' && dis[i][m-1]<mdis[i][m-1]) {
            eexit ={i,m-1};
            break;
        }
    }
    for(int i=0;i<m;i++) {
        if (grid[0][i]!='#'&& dis[0][i]<mdis[0][i]) {
            eexit={0,i};
            break;
        }
        if (grid[n-1][i]!='#' && dis[n-1][i]<mdis[n-1][i]) {
            eexit ={n-1,i};
            break;
        }
    }
    if (eexit==pii{-1,-1}) {
        cout << "NO\n";
        return;
    }
    int pathdis = dis[eexit.F][eexit.S];
    string path;
    pii curcell=eexit;
    while(pathdis>0) {
        auto &[x,y]=curcell;
        auto dircs = {tuple<int,int,char>{-1,0,'D'},{0,1,'L'},{1,0,'U'},{0,-1,'R'}};
        for(auto &[dx,dy,dir]:dircs) {
            int nx=x+dx,ny=y+dy;
            if (nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]=='#'||
                    dis[nx][ny]>=dis[x][y] ||dis[nx][ny]>=mdis[nx][ny]) {
                continue;
            }
            path.push_back(dir);
            x=nx,y=ny;
            pathdis--;
            break;
        }
    }
    reverse(all(path));
    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path <<"\n";
}


int main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
