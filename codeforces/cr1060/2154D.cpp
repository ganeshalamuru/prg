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
    vector<vector<int>> adj(n+1);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> pa(n+1,-1);
    vector<int> nodelvl(n+1,-1);
    auto dfs = [&](this auto self, int u, int p,int lvl) -> void {
        pa[u]=p;
        nodelvl[u]=lvl;
        for(int &v:adj[u]) {
            if (v==p)
                continue;
            self(v,u,lvl+1);
        }
    };
    dfs(1,0,0);
    set<int> path;
    vector<int> pathv;
    int pnode = n;
    while(pnode>0) {
        path.insert(pnode);
        pathv.push_back(pnode);
        pnode=pa[pnode];
    }
    reverse(all(pathv));
    vector<vector<int>> lvlnodes(n);
    for(int i=1;i<=n;i++) {
        if (path.find(i)==path.end())
            lvlnodes[nodelvl[i]].push_back(i);
    }
    int lastlvl = n-1;
    while (lastlvl>0 && lvlnodes[lastlvl].size()==0) {
        lastlvl--;
    }
    vector<array<int,2>>ops;
    int curlvlparity=0;
    while (lastlvl>0) {
        if (((lastlvl%2)^curlvlparity)==0) {
            if (ops.size()>0)
                ops.pop_back();
            else
                ops.push_back({1,0});
            curlvlparity^=1;
        }
        for(int &v:lvlnodes[lastlvl]) {
            ops.push_back({2,v});
            ops.push_back({1,0}),ops.push_back({1,0});
        }
        lastlvl--;
        while (lastlvl>0 && lvlnodes[lastlvl].size()==0) {
            lastlvl--;
        }
    }
    if (curlvlparity==0) {
        if (ops.size()>0)
            ops.pop_back();
        else
            ops.push_back({1,0});
    }
    pathv.pop_back();
    for(int &v:pathv) {
        ops.push_back({2,v});
        ops.push_back({1,0});
    }
    ops.pop_back();
    cout << ops.size() << "\n";
    for(auto &[op,node]:ops) {
        if (op==2) {
            cout << 2 << " " << node << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    cout << "\n";

}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
