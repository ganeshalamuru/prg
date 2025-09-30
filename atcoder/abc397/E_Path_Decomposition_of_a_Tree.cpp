#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void dfs(int u, vector<vector<int>>&adj, vector<int>&vis, vector<int>&dp) {
    vis[u]=1;
    int sz = 1;
    for(int &v:adj[u]) {
        if (vis[v]==1) {
            continue;
        }
        dfs(v,adj,vis,dp);
        sz+=dp[v];
    }
    dp[u]=sz;
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>>adj(n*k);
    for(int i=0,u,v;i<n*k-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (k==1) {
        cout << "Yes\n";
        return;
    }
    vector<int> dp(n*k, 0);
    vector<int> vis(n*k, 0);
    dfs(0,adj,vis,dp);
    vis = vector<int>(n*k, 0);
    function<bool(int u)> dfs2 = [&](int u) {
        vis[u]=1;
        int summ = 0,cnt = 0;
        for(int &v:adj[u]) {
            if (vis[v]==1)
                continue;
            if (!dfs2(v)) {
                return false;
            }
            if ((dp[v]%k)!=0) {
                cnt++;
                summ=(summ+dp[v]%k)%k;
            }
        }
        if (((n*k-dp[u])%k)!=0) {
            cnt++;
            summ=(summ+((n*k-dp[u])%k))%k;
        }
        if (summ!=k-1 || cnt>2)
            return false;
        else
            return true;
    };
    if (dfs2(0)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
