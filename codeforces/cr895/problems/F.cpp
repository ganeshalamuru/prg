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





void dfs(int node, vector<int> &edge, vector<int>& vis, vector<int> &cycleNodes, vector<int> &topoorder) {
    vis[node] = 1;
    if (vis[edge[node]] == 0)
        dfs(edge[node], edge, vis, cycleNodes, topoorder);
    else if (vis[edge[node]] == 1)
        cycleNodes.push_back(edge[node]);
    vis[node] = 2;
    topoorder.push_back(node);
}


void solve(){
	int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<ll> cost(n+1);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    for(int i=1;i<=n;i++)
        cin >> cost[i];
    vector<int> vis(n+1,0),res, topoorder, cycleNodes,parent(n+1, -1);
    for(int i=1;i<=n;i++)
        if(vis[i]==0)
            dfs(i, arr, vis, cycleNodes, topoorder);
    vis = vector<int>(n+1,0);
    for(int v:cycleNodes) {
        if (vis[v]==1)
            continue;
        ll u=v,mincost = INT_MAX, indexOfMinNode = -1;
        vector<int> nodesInCycle;
        while(vis[u] != 1) {
            vis[u] = 1;
            nodesInCycle.push_back(u);
            if (mincost > cost[u])
                mincost = cost[u], indexOfMinNode = nodesInCycle.size() - 1;
            u = arr[u];
        }
        for(int j=indexOfMinNode,i=0;i<nodesInCycle.size();i++,j--)
            res.push_back(nodesInCycle[(j+nodesInCycle.size())%(nodesInCycle.size())]);
    }
    for(int v:topoorder)
        if (vis[v]==0)
            res.push_back(v);
    reverse(res.begin(), res.end());
    for(int v:res)
        cout << v << " ";
    cout << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
