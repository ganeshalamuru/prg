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
	int h,w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i=0;i<h;i++) {
        cin >> grid[i];
    }
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--,b--,c--,d--;
    vector<vector<int>> cost(h,vector<int>(w,INT_MAX));
    set<vector<int>> ss;
    cost[a][b]=0;
    ss.insert({0,a,b});
    while(!ss.empty()) {
        auto itr = ss.begin();
        auto cell = *itr;
        if (cell[1]==c && cell[2]==d) {
            cout << cell[0] << "\n";
            return;
        }
        ss.erase(itr);
        int curx = cell[1],cury=cell[2];
        int moves = cell[0];
        for(auto &[dx,dy]:vector<pii>{{-1,0},{0,1},{1,0},{0,-1}}) {
            int newx=curx+dx,newy=cury+dy;
            if (newx<0 || newx>=h || newy<0 || newy>=w)
                continue;
            if (grid[newx][newy]=='.') {
                if (moves<cost[newx][newy]) {
                    ss.erase({cost[newx][newy],newx,newy});
                    cost[newx][newy]=moves;
                    ss.insert({cost[newx][newy],newx,newy});
                }
            } else {
                if (moves+1<cost[newx][newy]) {
                    ss.erase({cost[newx][newy],newx,newy});
                    cost[newx][newy]=moves+1;
                    ss.insert({cost[newx][newy],newx,newy});
                }
                if (abs(dx)>0) {
                    if (newx+dx>=0 && newx+dx<h) {
                        newx+=dx;
                        if (moves+1<cost[newx][newy]) {
                            ss.erase({cost[newx][newy],newx,newy});
                            cost[newx][newy]=moves+1;
                            ss.insert({cost[newx][newy],newx,newy});
                        }
                    }
                } else {
                    if (newy+dy>=0 && newy+dy<w) {
                        newy+=dy;
                        if (moves+1<cost[newx][newy]) {
                            ss.erase({cost[newx][newy],newx,newy});
                            cost[newx][newy]=moves+1;
                            ss.insert({cost[newx][newy],newx,newy});
                        }
                    }
                }
            }
        }
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
