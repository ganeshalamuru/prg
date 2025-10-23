#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
 

void dfs(int u,vector<int>&vis,vector<vector<pii>>&adj) {
    vis[u]=1;
    for(auto &[v,_]:adj[u]) {
        if (vis[v]==1 || vis[v]==2) {
            continue;
        } else {
            dfs(v,vis,adj);
        }
    }
    vis[u]=2;
}
 
void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n+1),radj(n+1);
    map<pii,int> edges;
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        auto itr=edges.find({a,b});
        if (itr==edges.end()) {
            edges[{a,b}]=-c;
        } else {
            itr->S = min(itr->S,-c);
        }
    }
    for(auto &[edge,c]:edges) {
        auto [u,v]=edge;
        adj[u].push_back({v,c});
        radj[v].push_back({u,c});
    }
    vector<int> vis1(n+1),visn(n+1),inpath(n+1);
    dfs(1,vis1,adj),dfs(n,visn,radj);
    for(int i=1;i<=n;i++) {
        inpath[i]=(vis1[i]==2 && visn[i]==2);
    }
    map<pii,int> newedges;
    for(auto &[edge,c]:edges) {
        auto [u,v]=edge;
        if (inpath[u]==1 && inpath[v]==1) {
            newedges[{u,v}]=c;
        }
    }
    vector<ll> dis(n+1,LLONG_MAX);
    dis[1]=min(0,newedges[{1,1}]);
    for(int i=1;i<n;i++) {
        bool change = false;
        for(auto &[edge,c]:newedges) {
            auto [u,v]=edge;
            if (dis[u]<LLONG_MAX && dis[u]+c<dis[v]) {
                change=true;
                dis[v]=dis[u]+c;
            }
        }
        if (!change) {
            break;
        }
    }
    for(auto &[edge,c]:newedges) {
        auto [u,v]=edge;
        if (dis[u]<LLONG_MAX && dis[u]+c<dis[v]) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << -dis[n] << "\n";
 
 
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
