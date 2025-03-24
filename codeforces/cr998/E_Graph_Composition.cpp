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

vector<vector<int>> parent,dsu_rank;
void initdsu(int n) {
    parent = vector<vector<int>>(2,vector<int>(n));
    dsu_rank = vector<vector<int>>(2,vector<int>(n,1));
    for(int i=0;i<n;i++)
        parent[0][i]=i,parent[1][i]=i;
}

int findrep(int i, int u) {
    if (parent[i][u]==u)
        return u;
    return parent[i][u] = findrep(i, parent[i][u]);
}

void dsu_union(int i, int u, int v) {
    int urep = findrep(i, u), vrep = findrep(i, v);
    if (urep == vrep)
        return;
    if (dsu_rank[i][urep]>dsu_rank[i][vrep]) {
        parent[i][urep] = vrep;
        dsu_rank[i][urep]+=dsu_rank[i][vrep];
    } else {
        parent[i][vrep] = urep;
        dsu_rank[i][vrep]+=dsu_rank[i][urep];
    }
}



void solve() {
	int n,m1,m2;
    cin >> n >> m1 >> m2;
    vector<pair<int,int>> fedges(m1), gedges(m2); 
    for(int i=0,u,v;i<m1;i++) {
        cin >> u >> v;
        u--,v--;
        fedges[i] = {u,v};
    }
    for(int i=0,u,v;i<m2;i++) {
        cin >> u >> v;
        u--,v--;
        gedges[i] = {u,v};
    }
    initdsu(n);
    int ans = 0;
    for(int i=0;i<m2;i++)
        dsu_union(1, gedges[i].F, gedges[i].S);
    for(int i=0;i<m1;i++) {
        if (findrep(1, fedges[i].F) != findrep(1, fedges[i].S)) {
            ans++;
            continue;
        }
        dsu_union(0, fedges[i].F, fedges[i].S);
    }
    for(int i=0;i<m2;i++) {
        if (findrep(0, gedges[i].F) == findrep(0, gedges[i].S))
            continue;
        dsu_union(0, gedges[i].F, gedges[i].S);
        ans++;
    }
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
