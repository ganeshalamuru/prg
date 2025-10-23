#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n;
    cin >> n;
    vector<vector<int>>minmoves(n,vector<int>(n,INT_MAX));
    minmoves[0][0]=0;
    queue<pii> q({{0,0}});
    while(!q.empty()) {
        auto& [x,y]=q.front();
        for(auto& [dx,dy]:{pii{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}}) {
            int nx=x+dx,ny=y+dy;
            if (nx<0 || nx>=n || ny<0||ny>=n || minmoves[nx][ny]!=INT_MAX)
                continue;
            minmoves[nx][ny]=minmoves[x][y]+1;
            q.push({nx,ny});
        }
        q.pop();
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << minmoves[i][j] << " ";
        }
        cout << "\n";
    }



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
