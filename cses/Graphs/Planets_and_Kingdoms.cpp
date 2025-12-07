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
	int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1),radj(n+1);
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vector<int> postorder_of_revg;
    vector<int> vis(n+1,0);
    function<void(int)> dfs = [&](int u) {
        vis[u]=1;
        for(int v:radj[u]) {
            if (vis[v]!=0)
                continue;
            dfs(v);
        }
        postorder_of_revg.push_back(u);
    };
    for(int i=1;i<=n;i++) {
        if (vis[i]!=0)
            continue;
        dfs(i);
    }
    fill(all(vis),0);
    int compno = 0;
    while(!postorder_of_revg.empty()) {
        int node = postorder_of_revg.back();
        postorder_of_revg.pop_back();
        if (vis[node]!=0)
            continue;
        compno++;   
        function<void(int)> dfs2=[&](int u) {
            vis[u]=compno;
            for(int v:adj[u]) {
                if (vis[v]!=0)
                    continue;
                dfs2(v);
            }
        };
        dfs2(node);
    }
    cout << compno << "\n";
    for(int i=1;i<=n;i++) {
        cout << vis[i] << " ";
    }
    cout << "\n";



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
