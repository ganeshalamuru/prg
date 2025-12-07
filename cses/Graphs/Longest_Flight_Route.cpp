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
    vector<vector<int>> adj(n+1);
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int>distn(n+1,INT_MIN),maxpathnode(n+1,0),vis(n+1,0);
    function<void(int)> dfs = [&](int u) {
        vis[u]=1;
        for(int &v:adj[u]) {
            if (vis[v]==0)
                dfs(v);
            if (distn[v]!=INT_MIN && distn[v]+1>distn[u])
                distn[u]=distn[v]+1,maxpathnode[u]=v;
        }
        if (u==n)
            distn[u]=0;
    };
    dfs(1);
    if (distn[1]==INT_MIN) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int>path;
    int curnode = 1;
    while (curnode>0) {
        path.push_back(curnode);
        curnode=maxpathnode[curnode];
    }
    cout << path.size() << "\n";
    for(int &v:path)
        cout << v << " " ;
    cout << "\n";
    

}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
