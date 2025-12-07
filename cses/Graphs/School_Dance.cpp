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

int augmentpathflow(int target, int n, vector<vector<int>>&adj, vector<vector<int>>&flow) {
    vector<vector<int>> resadj(n);
    for(int a=0;a<n;a++) {
        for(int b:adj[a]) {
            if (1-flow[a][b]>0)
                resadj[a].push_back(b);
            if (flow[a][b]>0)
                resadj[b].push_back(a);
        }
    }
    queue<int> q;
    vector<int> vis(n,0),pa(n,-1);
    vis[0]=1;
    q.push(0);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for(int v:resadj[u])
            if (vis[v]==0)
                q.push(v),pa[v]=u,vis[v]=1;
    }
    if (vis[target]==0)
        return 0;
    int pnode = target;
    while (pa[pnode]>-1) {
        //cout << pa[pnode] << " " << pnode << "\n" << flush;
        if (flow[pa[pnode]][pnode]!=-1)
            flow[pa[pnode]][pnode]+=1;
        if (flow[pnode][pa[pnode]]!=-1)
            flow[pnode][pa[pnode]]-=1;
        pnode = pa[pnode];
    }
    //cout << "flow " << "\n" << flush;
    return 1;
}

void solve() {
	int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n+m+2),flow(n+m+2,vector<int>(n+m+2,-1));
    set<pii> ss;
    for(int i=0,b,g;i<k;i++) {
        cin >> b >> g;
        g+=n;
        if (ss.find({b,g})==ss.end())
            adj[b].push_back(g),ss.insert({b,g}),flow[b][g]=0;
    }
    for(int i=1;i<=n;i++) {
        adj[0].push_back(i);
        flow[0][i]=0;
    }
    for(int i=n+1;i<=n+m;i++) {
        adj[i].push_back(n+m+1);
        flow[i][n+m+1]=0;
    }
    int maxflow = 0, tmpflow = augmentpathflow(n+m+1,n+m+2,adj,flow);
    for(;tmpflow>0;tmpflow=augmentpathflow(n+m+1,n+m+2,adj,flow))
        maxflow+=tmpflow;
    //cout << "maxflow " << maxflow << "\n" << flush;
    vector<vector<int>> resadj(n+m+2);
    for(int a=0;a<n+m+2;a++) {
        for(int b:adj[a]) {
            if (1-flow[a][b]>0)
                resadj[a].push_back(b);
            if (flow[a][b]>0)
                resadj[b].push_back(a);
        }
    }
    cout << maxflow << "\n";
    for(int b=1;b<=n;b++) {
        for(int g:adj[b]) {
            if (flow[b][g]==1) {
                cout << b << " " << g-n << "\n";
            }
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
