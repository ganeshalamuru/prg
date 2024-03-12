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


bool identityperm(int n, vector<int> &arr) {
    for(int i=1;i<=n;i++)
        if (arr[i]!=i)
            return false;
    return true;
}

void dfs(int node, vector<int> &b, vector<int> &vis, vector<int>& cycleNodes) {
    vis[node] = 1;
    if (vis[b[node]] == 0)
        dfs(b[node], b, vis, cycleNodes);
    else if (vis[b[node]] == 1)
        cycleNodes.push_back(b[node]);
    vis[node] = 2;
}


void solve(){
	int n,k;
    cin >> n >> k;
    vector<int>b(n+1);
    for(int i=1;i<=n;i++)
        cin >> b[i];
    if (k==1) {
        if (identityperm(n, b))
            cout << "yes\n";
        else
            cout << "no\n";
        return;
    }
    vector<int> vis(n+1,0),cycleNodes;
    for(int i=1;i<=n;i++)
        if (vis[i]!=1)
            dfs(i,b,vis,cycleNodes);
    vis = vector<int>(n+1,0);
    for(int v:cycleNodes) {
        if  (vis[v]==1)
            continue;
        int u = v,len=0;
        while(vis[u] != 1)
            vis[u]=1, u=b[u], len++;
        if (len!=k) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
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
