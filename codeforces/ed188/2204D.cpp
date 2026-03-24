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
    vector<vector<int>> adj(n+1);
    for(int i=0,u,v;i<m;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    int ans = 0;

    for(int i=1;i<=n;i++) {
        if (vis[i]==1)
            continue;
        map<int,int> depth;
        queue<int>q;
        q.push(i);
        vis[i]=1;
        depth[i]=0;
        bool possible=true;
        while (q.size()>0) {
            int qsz = int(q.size());
            while (qsz--) {
                int u = q.front();
                q.pop();
                for(int v:adj[u]) {
                    if (vis[v]==1) {
                        if (depth[u]%2 == depth[v]%2) {
                            possible = false;
                        }
                        continue;
                    }
                    vis[v]=1;
                    depth[v]=depth[u]+1;
                    q.push(v);
                }
            }
        }
        if (possible) {
            int oddcnt=0,envcnt =0;
            for(auto nodedepth:depth) {
                if (nodedepth.second%2 == 0)
                    envcnt++;
                else
                    oddcnt++;
            }
            ans+=max(oddcnt,envcnt);
        }
    }
    cout << ans << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
