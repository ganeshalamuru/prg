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
    vector<vector<int>>resadj(n+1);
    for(int a=1;a<=n;a++) {
        for(int b:adj[a]) {
            if (1-flow[a][b]>0)
                resadj[a].push_back(b);
            if (flow[a][b]>0)
                resadj[b].push_back(a);
        }
    }
    queue<int> q;
    vector<int>vis(n+1,0),pa(n+1,0);
    vis[1]=1,q.push(1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for(int v:resadj[u]) {
            if (vis[v]==0)
                vis[v]=1,q.push(v),pa[v]=u;
        }
    }
    if (vis[target]==0)
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
vector<int> decomposeflow(int target, int n, vector<vector<int>> &adj, vector<vector<int>> &flow) {
    queue<int> q;
    vector<int>vis(n+1,0),pa(n+1,0);
    vis[1]=1,q.push(1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for(int v:adj[u]) {
            if (vis[v]==0 && flow[u][v]==1)
                vis[v]=1,q.push(v),pa[v]=u;
        }
    }
    if (vis[target]==0)
        return {};
    vector<int> singlestflow;
    int node = target;
    while(node > 0) {
        singlestflow.push_back(node);
        node = pa[node];
    }
    reverse(all(singlestflow));
    for(int i=0;i<int(singlestflow.size())-1;i++) {
        int u = singlestflow[i], v = singlestflow[i+1];
        flow[u][v]-=1;
    }
    return singlestflow;
}



void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+m+1),flow(n+m+1,vector<int>(n+m+1,-1));
    for(int i=1,a,b;i<=m;i++) {
        cin >> a >> b;
        if (a==b) continue;
        adj[a].push_back(n+i);
        adj[n+i].push_back(b);
        flow[a][n+i]=flow[n+i][b]=0;
    }
    int maxflow =0, tmpflow = augmentpathflow(n,n+m,adj,flow);
    while (tmpflow > 0) {
        maxflow+=tmpflow;
        tmpflow = augmentpathflow(n,n+m,adj,flow);
    }
    cout << maxflow << "\n";
    vector<int> flowpath = decomposeflow(n,n+m,adj,flow);
    while(int(flowpath.size()) > 0) {
        int extravert = 0;
        for(int u:flowpath)
            if (u>n)
                extravert++;
        cout << int(flowpath.size())-extravert << "\n";
        for(int u:flowpath) {
            if (u<=n)
                cout << u << " ";
        }
        cout << "\n";
        flowpath = decomposeflow(n,n+m,adj,flow);
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
