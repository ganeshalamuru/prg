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
    vector<string> grid(n);
    for(auto &str:grid)
        cin >> str;
    string ans(2*n-1,'$');
    vector<vector<int>> vis(n,vector<int>(n,0));
    vis[0][0]=1;
    for(int d=0;d<2*n-1;d++) {
        char smallchar = 'Z';
        int x=0,y=0;
        if (d<n) 
            x=d,y=0;
         else
            x=n-1,y=d-n+1;
        for(;x>=0&&y<n;x--,y++) {
            if (vis[x][y]==1) {
                smallchar = min(smallchar,grid[x][y]);
                //cout << "gruid " << grid[x][y] << "\n";
            }
        }
        //cout << "smallchar " << smallchar << "\n";
        if (d<n) 
            x=d,y=0;
         else
            x=n-1,y=d-n+1;
        for(;x>=0&&y<n;x--,y++) {
            if (smallchar==grid[x][y] && vis[x][y]==1) {
                //grid[x][y]='@';
                if (x+1<n) {
                    vis[x+1][y]=1;
                } 
                if (y+1<n){
                    vis[x][y+1]=1;
                }
            }
        }
        ans[d]=smallchar;
    }
    cout << ans <<"\n";
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
