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


void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &pa, vector<int>&c, vector<int>&numbc) {
    pa[u]=p;
    int nbc = 0;
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        if (c[v]==1)
            nbc++;
        dfs(v,u,adj,pa,c,numbc);
    }
    numbc[u]=nbc;
}


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> c(n);
    for(int i=0;i<n;i++)
        cin >> c[i];
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>pa(n),numbc(n);
    dfs(0,-1,adj,pa,c,numbc);
    set<pii> ss;
    for(int i=0;i<n;i++) {
        if (c[i]==1)
            ss.insert({numbc[i], i});
    }
    while(q--) {
        int u;
        cin >> u;
        u--;
        if (c[u]==1) {
            ss.erase({numbc[u], u});
            if (pa[u]!= -1) {
                if (c[pa[u]]==1) {
                    ss.erase({numbc[pa[u]], pa[u]});
                    numbc[pa[u]]--;
                    ss.insert({numbc[pa[u]], pa[u]});
                } else {
                    numbc[pa[u]]--;
                }
            }
            c[u]=0;
        } else {
            ss.insert({numbc[u], u});
            if (pa[u]!= -1) {
                if (c[pa[u]]==1) {
                    ss.erase({numbc[pa[u]], pa[u]});
                    numbc[pa[u]]++;
                    ss.insert({numbc[pa[u]], pa[u]});
                } else {
                    numbc[pa[u]]++;
                }
            }
            c[u]=1;
        }
        if (ss.size()==0) {
            cout << "No\n";
        } else if (ss.size() == 1) {
            cout << "Yes\n";
        } else if (ss.size() == 2) {
            auto itr2 = ++ss.begin();
            if (itr2->F == 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            auto itr2= ++ss.begin(), itr3=++(++ss.begin());
            auto eitr = ss.rbegin();
            if (eitr->F<1 || eitr->F>2) {
                cout << "No\n";
            } else if (eitr->F==1) {
                if (itr2->F==0) {
                    cout << "No\n";
                } else {
                    cout << "Yes\n";
                }
            } else {
                if ((--eitr)->F==2 || c[pa[ss.rbegin()->S]]==1 || itr3->F==0) {
                    cout << "No\n";
                } else {
                    cout << "Yes\n";
                }
            }
        }
    }


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
