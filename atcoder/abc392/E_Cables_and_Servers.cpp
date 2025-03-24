#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e5+1, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


vector<int> parent,dsu_rank;

void dsu_init(int n) {
    parent.resize(n);
    dsu_rank.resize(n);
    for(int i=0;i<n;i++)
        parent[i]=i,dsu_rank[i]=0;
}

int dsu_findrep(int u) {
    if (parent[u]==u)
        return u;
    return parent[u] = dsu_findrep(parent[u]);
}

void dsu_union(int u, int v) {
    int urep = dsu_findrep(u), vrep = dsu_findrep(v);
    if (urep==vrep)
        return ;
    int ureprank = dsu_rank[urep], vreprank = dsu_rank[vrep];
    if (ureprank < vreprank) {
        parent[urep]=vrep;
        dsu_rank[vrep]+=dsu_rank[ureprank];
    } else {
        parent[vrep]=urep;
        dsu_rank[urep]+=dsu_rank[vrep];
    }
}


void solve() {
	int n,m;
    cin >> n >> m;
    dsu_init(n);
    vector<pii> extraedges;
    for(int i=0,u,v;i<m;i++) {
        cin >> u >> v;
        u--,v--;
        if (dsu_findrep(u) == dsu_findrep(v))
            extraedges.push_back({i,v});
        else
            dsu_union(u,v);
    }
    if (extraedges.size()==0) {
        cout << 0 << "\n";
        return;
    }
    vector<int> ccrep(n,0);
    for(int i=0;i<n;i++)
        ccrep[i]=(parent[i]==i);
    map<int,vector<pii>> extraedges_of_cc;
    for(auto &[i,v]:extraedges) {
        int repp = dsu_findrep(v);
        extraedges_of_cc[repp].push_back({i,v});
        ccrep[repp]=2;
    }
    vector<vector<int>> ans;
    map<int,vector<pii>>::iterator pitr = extraedges_of_cc.begin(),itr = ++extraedges_of_cc.begin();
    while(itr!=extraedges_of_cc.end()) {
        auto pp = pitr->second.back();
        pitr->second.pop_back();
        ans.push_back({pp.F,pp.S,itr->first});
        pitr=itr;
        itr++;
    }
    itr = extraedges_of_cc.begin();
    for(int i=0;i<n;i++) {
        if (ccrep[i]==0 || ccrep[i]==2)
            continue;
        while(itr->second.size()==0)
            itr++;
        auto pp = itr->second.back();
        itr->second.pop_back();
        ans.push_back({pp.F, pp.S, i});
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) {
        cout << ans[i][0]+1 << " " <<ans[i][1]+1<<" " << ans[i][2]+1 << "\n";
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
