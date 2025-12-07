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


ll augmentpathflow(int target, int n,vector<vector<pair<int,ll>>> &adj, vector<vector<ll>>&flow) {
    vector<vector<pair<int,ll>>> resadj(n+1);
    for(int a=1;a<=n;a++) {
        for(auto [b,c]:adj[a]) {
            if (c-flow[a][b]>0) {
                resadj[a].push_back({b,c-flow[a][b]});
            }
            if (flow[a][b]>0) {
                resadj[b].push_back({a,flow[a][b]});
            }
        }
    }
    // find largest bottleneck path, update flow of edges and reutrn augmented path flow
    set<pair<ll,int>,greater<pair<ll,int>>> ss;
    vector<ll>spd(n+1,0);
    vector<int>pa(n+1,0);
    spd[1]=LLONG_MAX;
    ss.insert({spd[1],1});
    while(!ss.empty()) {
        auto [speed, node] = *ss.begin();
        ss.erase({speed, node});
        for(auto [v,linkspeed]:resadj[node]) {
            if (spd[v]==0) {
                spd[v]=min(linkspeed, speed);
                pa[v]=node;
                ss.insert({spd[v],v});
            } else if (min(linkspeed, speed) > spd[v]) {
                ss.erase({spd[v],v});
                spd[v]=min(linkspeed, speed);
                pa[v]=node;
                ss.insert({spd[v],v});
            }
        }
    }
    if (spd[target]==0)
        return 0;
    int pnode = target;
    while(pa[pnode]!=0) {
        if (flow[pa[pnode]][pnode]!=-1) {
            flow[pa[pnode]][pnode]+=spd[target];
        }
        if (flow[pnode][pa[pnode]]!=-1) {
            flow[pnode][pa[pnode]]-=spd[target];
        }
        pnode = pa[pnode];
    }
    return spd[target];
}


void solve() {
	int n,m;
    cin >> n >> m;
    int numnodes = n;
    vector<pii> edges;
    vector<vector<ll>> capacity(n+1,vector<ll>(n+1));
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        if (a==b)
            continue;
        if (capacity[a][b]==0)
            edges.push_back({a,b});
        capacity[a][b]+=c;
    }
    vector<array<ll,3>> nedges;
    for(auto [a,b]:edges) {
        if (capacity[b][a]>0) {
            nedges.push_back({a,numnodes+1,capacity[a][b]});
            nedges.push_back({numnodes+1,b,capacity[a][b]});
            numnodes+=1;
        } else {
            nedges.push_back({a,b,capacity[a][b]});
        }
        
    }
    vector<vector<pair<int,ll>>> adj(numnodes+1);
    vector<vector<ll>> flow(numnodes+1,vector<ll>(numnodes+1,-1));
    for(auto [a,b,c]:nedges) {
        adj[a].push_back({b,c});
        flow[a][b]=0;
    }
    ll maxspeed = 0, tmpspeed = augmentpathflow(n,numnodes, adj,flow);
    for (;tmpspeed>0;tmpspeed = augmentpathflow(n,numnodes, adj,flow)) {
        maxspeed+=tmpspeed;
    }
    cout << maxspeed << "\n";
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
