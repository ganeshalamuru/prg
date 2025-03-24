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
	int n;
    cin >> n;
    vector<string> adj(n);
    for(int i=0;i<n;i++) {
        cin >> adj[i];
    }
    vector<vector<int>> d(n,vector<int>(n,INT_MAX));
    set<vector<int>> ss;
    for(int i=0;i<n;i++)
        ss.insert({0,i,i}),d[i][i]=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (i!=j && adj[i][j]!='-')
                ss.insert({1,i,j}),d[i][j]=1;
        }
    }
    while(!ss.empty()) {
        auto pp = *ss.begin();
        int dis = pp[0], leftn = pp[1], rightn=pp[2];
        ss.erase(ss.begin());
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (adj[i][leftn] == adj[rightn][j] && adj[i][leftn]!='-') {
                    if (dis+2 < d[i][j]) {
                        ss.erase({d[i][j],i,j});
                        d[i][j]=dis+2;
                        ss.insert({d[i][j],i,j});
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (d[i][j]==INT_MAX)
                cout << -1 << " ";
            else
                cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
