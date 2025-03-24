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


vector<int> parent,dsu_rank;
void initdsu(int n) {
    parent.resize(n);
    dsu_rank = vector<int>(n,1);
    for(int i=0;i<n;i++)
        parent[i]=i;
}

int findrep(int u) {
    if (parent[u]==u)
        return u;
    return parent[u] = findrep(parent[u]);
}

void dsu_union(int u, int v) {
    int urep = findrep(u), vrep = findrep(v);
    if (urep == vrep)
        return;
    if (dsu_rank[urep]>dsu_rank[vrep]) {
        parent[urep] = vrep;
        dsu_rank[urep]+=dsu_rank[vrep];
    } else {
        parent[vrep] = urep;
        dsu_rank[vrep]+=dsu_rank[urep];
    }
}


void solve() {
	int n,m,k;
    cin >> n >> m >> k;
    initdsu(n);
    vector<int> num(k);
    for(int i=0;i<k;i++)
        cin >> num[i];
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0,u,v,c;i<m;i++) {
        cin >> u >> v >> c;
        u--,v--;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    for(int u=0;u<n;u++) {
        for(auto &[v,c]:adj[u]) {
            if (c!=0)
                continue;
            dsu_union(u,v);
        }
    }
    vector<vector<int>> ans(k,vector<int>(k,INT_MAX));
    vector<int> findtype(n,0);
    for(int i=0,sum=0;i<k;i++) {
        int irep = findrep(sum);
        for(int j=sum;j<sum+num[i];j++) {
            int jrep = findrep(j);
            if (irep!=jrep) {
                cout << "No\n";
                return;
            }
            findtype[j]=i;
        }
        ans[i][i]=0;
        sum+=num[i];
    }
    cout << "Yes\n";
    for(int u=0;u<n;u++) {
        int utype = findtype[u];
        for(auto &[v,c]:adj[u]) {
            int vtype = findtype[v];
            if (utype==vtype)
                continue;
            ans[utype][vtype] = min(ans[utype][vtype], c);
            ans[vtype][utype] = min(ans[vtype][utype], c);
        }
    }
    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            for(int z=0;z<k;z++) {
                if (ans[j][i]!=INT_MAX && ans[i][z]!=INT_MAX)
                    ans[j][z] = min(ans[j][z], ans[j][i]+ans[i][z]);
            }
        }
    }
    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            if (ans[i][j]==INT_MAX)
                cout << -1 << " ";
            else
                cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
