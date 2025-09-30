#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


vector<vector<vector<int>>> vis(1000,vector<vector<int>>(1000,vector<int>({0,-1,-1,-1})));
void solve() {
	int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
        cin >> grid[i];
    int si=0,sj=0,ei=0,ej=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (grid[i][j]=='A') {
                si=i,sj=j;
            }
            if (grid[i][j]=='B') {
                ei=i,ej=j;
            }
        }
    }
    
    queue<pii> qq;
    qq.push({si,sj});
    map<int,char> mov{{0,'U'},{1,'R'},{2,'D'},{3,'L'}};
    vis[si][sj]={1,-1,-1,-1};
    while(!qq.empty()) {
        int i = qq.front().F,j=qq.front().S;
        qq.pop();
        for(auto &vv:vector<vector<int>>{{-1,0,0},{0,1,1},{1,0,2},{0,-1,3}}) {
            int dx = vv[0],dy=vv[1];
            int nx=i+dx,ny=j+dy;
            if (nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny][0]==1 || grid[nx][ny]=='#') {
                continue;
            }
            vis[nx][ny]={1,i,j,vv[2]};
            qq.push({nx,ny});
        }
    }
    if (vis[ei][ej][3]!=-1) {
        cout << "YES\n";
        stack<char> moves;
        int ci=ei,cj=ej;
        while(vis[ci][cj][3]!=-1) {
            auto temp = vis[ci][cj];
            moves.push(mov[temp[3]]);
            ci=temp[1],cj=temp[2];
        }
        cout << moves.size() << "\n";
        while (!moves.empty()) {
            cout << moves.top();
            moves.pop();
        }
        cout << "\n";
        
    } else {
        cout << "NO\n";
    }

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
