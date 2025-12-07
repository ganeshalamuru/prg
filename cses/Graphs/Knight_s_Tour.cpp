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
	int x,y;
    cin >> x >> y;
    vector<string> gm(9,string(9,'0'));
    map<pii,pii> adj;
    int cnt=1;
    for(auto [sx,sy]:{pii{1,1},{1,2},{2,1},{2,2}}) {
        for(auto [offset,sz]:{pii{0,8},{2,4}}) {
            int curx=sx,cury=sy;

            for(auto &[dx,dy]:{pii{1,2},{2,1},{1,-2},{-2,1}}) {
                int nx = 0,ny=0,times = sz/2-1;
                while(times--) {
                    if (dx==1) {
                        if (curx<=2)
                            nx=(curx==2?1:2);
                        else
                            nx=(curx==sz?sz-1:sz);    
                    } else {
                        nx=curx+dx; 
                    }
                    if (dy==1) {
                        if (cury<=2)
                            ny=(cury==2?1:2);
                        else
                            ny=(cury==sz?sz-1:sz);  
                    } else {
                        ny=cury+dy;
                    }
                    adj[{offset+curx,offset+cury}]={offset+nx,offset+ny};
                    gm[offset+nx][offset+ny]=char('0'+cnt);
                    curx=nx,cury=ny;
                }
            }
            cnt++;
        }
    }
    vector<vector<int>> ans(9,vector<int>(9,0));
    adj[{2,3}]={4,4};
    adj[{6,3}]={7,1};
    adj[{8,3}]={6,4};
    adj[{5,6}]={7,7};
    adj[{5,8}]={6,6};
    adj[{4,5}]={5,7};
    adj[{3,8}]={4,6};
    adj[{3,4}]={1,5};
    vector<vector<int>> vis(9,vector<int>(9,0));
    int viscnt=1;
    function<void(int,int)> dfs=[&](int i,int j) {
        vis[i][j]=viscnt++;
        auto [nx,ny]=adj[{i,j}];
        if (vis[nx][ny]!=0)
            return;
        dfs(nx,ny);
    };
    dfs(1,5);
    int offset = vis[y][x];
    for(int i=1;i<=8;i++) {
        for(int j=1;j<=8;j++) {
            cout << ((vis[i][j]-offset+64)%64) + 1 << " ";
        }
        cout << "\n";
    }

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
