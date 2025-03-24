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


void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &dpnum, vector<int> &dpseminum) {
    vector<int> childsemisz;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs(v,u,adj,dpnum, dpseminum);
        childsemisz.push_back(dpseminum[v]);
    }
    dpseminum[u]=1;
    dpnum[u]=0;
    sort(childsemisz.rbegin(), childsemisz.rend());
    if (childsemisz.size()>3)
        dpnum[u] = childsemisz[0]+childsemisz[1]+childsemisz[2]+childsemisz[3] + 1;
    else if (childsemisz.size()>0)
        dpnum[u] = childsemisz[0] + 1;
    if (childsemisz.size()>2)
        dpseminum[u] = childsemisz[0]+childsemisz[1]+childsemisz[2] + 1;
}

void solve() {
	int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    // maxsemialkane(i.e root is deg 0, or deg 3)
    vector<int> dpseminum(n,0);
    // max alkane subtree
    vector<int> dpnum(n,0);
    dfs(0,-1,adj,dpnum, dpseminum);
    int ans = 0;
    function<void(int,int, int)> dfs2=[&](int u,int p, int maxsemipathsz) {
        ans = max(ans, dpnum[u]);
        ans = max(ans, maxsemipathsz+1);
        multiset<int,greater<int>> childsemisz;
        for(int &v:adj[u]) {
            if (v==p)
                continue;
            childsemisz.insert(dpseminum[v]);
        }
        if (childsemisz.size()>2) {
            auto itr = childsemisz.begin();
            int esz=*itr;
            esz+=*(++itr);
            esz+=*(++itr);
            ans = max(ans, maxsemipathsz+1+esz);
        }
        for(int &v:adj[u]) {
            if (v==p)
                continue;
            if (childsemisz.size()<3) {
                dfs2(v,u,1);
            } else {
                auto titr = childsemisz.find(dpseminum[v]);
                if (titr!=childsemisz.end())
                    childsemisz.erase(titr);
                auto itr = childsemisz.begin();
                int esz=*itr;
                esz+=*(++itr);
                dfs2(v,u,maxsemipathsz+1+esz);
                childsemisz.insert(dpseminum[v]);
            }
        }
    };
    ans = max(ans, dpnum[0]);
    multiset<int,greater<int>> childsemisz;
    for(int &v:adj[0])
        childsemisz.insert(dpseminum[v]);
    for(int &v:adj[0]) {
        if (childsemisz.size()<4) {
            dfs2(v,0,1);
        } else {
            auto titr = childsemisz.find(dpseminum[v]);
            if (titr!=childsemisz.end())
                childsemisz.erase(titr);
            auto itr = childsemisz.begin();
            int esz=*itr;
            esz+=*(++itr);
            esz+=*(++itr);
            dfs2(v,0,1+esz);
            childsemisz.insert(dpseminum[v]);
        }
    }
    if (ans == 2 || ans == 0) 
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
