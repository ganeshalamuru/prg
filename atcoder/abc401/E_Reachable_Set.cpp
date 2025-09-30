#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0,u,v;i<m;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n,0);
    set<int> ss;
    vector<int> ans(n,-1);
    int j=0,maxvisted=0;
    ss.insert(0);
    int nodetovis = 0;
    while (!ss.empty()) {
        int node = *ss.begin();
        vis[node]=1;
        maxvisted=max(maxvisted,node);
        while(j<n && vis[j]==1)
            j++;
        ss.erase(node);
        for(int &v:adj[node]) {
            if (vis[v]==1)
                continue;
            ss.insert(v);
        }
        if (maxvisted<=j-1)
            ans[j-1]=ss.size();
        nodetovis++;
    }
    for(int i=0;i<n;i++) {
        cout << ans[i] << "\n";
    }
}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
