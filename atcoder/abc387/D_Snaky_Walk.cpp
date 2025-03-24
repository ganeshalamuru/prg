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




void solve() {
	int h,w;
    cin >> h >> w;
    vector<string> gd(h);
    for(int i=0;i<h;i++)
        cin >> gd[i];
    pii st,gg;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if (gd[i][j]=='S') {
                st={i,j};
            } else if (gd[i][j]=='G')
                gg={i,j};
        }
    }
    vector<vector<vector<int>>> dis(h,vector<vector<int>>(w,vector<int>(2,INT_MAX)));
    set<vector<int>> ss;
    dis[st.F][st.S][0] = 0;
    dis[st.F][st.S][1] = 0;
    ss.insert({0,st.F, st.S,0});
    ss.insert({0,st.F,st.S,1});
    while(!ss.empty()) {
        auto itr = ss.begin();
        auto ft = *itr;
        ss.erase(itr);
        for(auto &dd:vector<vector<int>>{{0,-1,0},{-1,0,1},{0,1,0},{1,0,1}}) {
            if ((dd[2]^ft[3])==0)
                continue;
            int nx = ft[1] + dd[0],ny = ft[2]+dd[1];
            if (nx>=0 && nx<h && ny>=0 && ny<w && gd[nx][ny]!='#' && ft[0]+1<dis[nx][ny][dd[2]]) {
                ss.erase({dis[nx][ny][dd[2]], nx, ny, dd[2]});
                dis[nx][ny][dd[2]]=ft[0]+1;
                ss.insert({dis[nx][ny][dd[2]], nx, ny, dd[2]});
            }
        }
    }
    int ans = min(dis[gg.F][gg.S][0], dis[gg.F][gg.S][1]); 
    if ( ans == INT_MAX)
        cout << -1 << "\n";
    else
        cout << ans << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
