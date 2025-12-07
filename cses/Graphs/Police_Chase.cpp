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


int augmentpathflow(int target, int n, vector<vector<int>> &adj, vector<vector<int>> &flow) {
    vector<vector<int>> resadj(n+1);
    for(int a=1;a<=n;a++) {
        for(int b:adj[a]) {
            if (1-flow[a][b]>0)
                resadj[a].push_back(b);
            if (flow[a][b]>0)
                resadj[b].push_back(a);
        }
    }
    queue<int> q;
    q.push(1);
    vector<int> lvl(n+1,-1),pa(n+1,0);
    lvl[1]=0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for(int v:resadj[node]) {
            if (lvl[v]==-1) {
                q.push(v);
                lvl[v]=lvl[node]+1;
                pa[v]=node;
            }
        }
    }
    if (lvl[target]==-1)
        return 0;
    int pnode = target;
    while(pa[pnode]>0) {
        if (flow[pa[pnode]][pnode]!=-1)
            flow[pa[pnode]][pnode]+=1;
        if (flow[pnode][pa[pnode]]!=-1)
            flow[pnode][pa[pnode]]-=1;
        pnode = pa[pnode];
    }
    return 1;
}


void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+2*m+1);
    vector<pii> edges;
    vector<vector<int>> flow(n+2*m+1,vector<int>(n+2*m+1,-1));
    for(int i=1,a,b;i<=m;i++) {
        cin >> a >> b;
        if (a==b) continue;
        edges.push_back({a,b});
        adj[a].push_back(n+2*i-1);
        adj[n+2*i-1].push_back(b);
        flow[a][n+2*i-1]=flow[n+2*i-1][b]=0;
        
        adj[b].push_back(n+2*i);
        adj[n+2*i].push_back(a);
        flow[b][n+2*i]=flow[n+2*i][a]=0;
    }
    int maxflow = 0, tmpflow = augmentpathflow(n,n+2*m,adj,flow);
    for(;tmpflow>0;tmpflow = augmentpathflow(n,n+2*m,adj,flow))   
        maxflow+=tmpflow;
    vector<vector<int>> resadj(n+2*m+1);
    for(int a=1;a<=n+2*m;a++) {
        for(int b:adj[a]) {
            if (1-flow[a][b]>0)
                resadj[a].push_back(b);
            if (flow[a][b]>0)
                resadj[b].push_back(a);
        }
    }
    vector<int> vis(n+2*m+1,0);
    function<void(int,int)> dfs = [&](int u,int mark) {
        vis[u]=mark;
        for(int v:resadj[u]) {
            if (vis[v]==0)
                dfs(v,mark);
        }
    };
    dfs(1,1);
    dfs(n,n);
    cout << maxflow << "\n";
    for(auto [u,v]:edges) {
        if ((vis[u]==1 && vis[v]==n) || (vis[u]==n && vis[v]==1)) {
            cout << u << " " << v << "\n";
        }
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
