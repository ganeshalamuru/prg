#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 998244353;


void solve() {
	int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i]--;
        adj[a[i]].push_back(i);
    }
    vector<int> roots;
    // cycle 3, tail 2, currently exploring 1
    vector<int> vis(n,0);
    for(int i=0;i<n;i++) {
        if (vis[i]!=0)
            continue;
        int j=i;
        while(vis[j]==0) {
            vis[j]=1;
            j=a[j];
        }
        // start is not cycle root
        if (j!=i) {
            int tt = i;
            while (tt!=j) {
                vis[tt]=2;
                tt=a[tt];
            }
        }
        if (vis[j]!=1)
            continue;
        int prev=-1;
        while(vis[j]!=3) {
            vis[j]=3;
            prev=j;
            j=a[j];
        }
        adj[j].erase(find(all(adj[j]),prev));
        roots.push_back(j);
        int trav = a[j];
        while(trav!=j) {
            for(int &v:adj[trav]) {
                if (vis[v]!=3) {
                    vis[v]=2;
                    adj[j].push_back(v);
                }
            }
            trav=a[trav];
        } 
    }
    vector<vector<int>> dp(n,vector<int>(m+1));
    function<void(int)> dfs=[&](int u) {
        if (adj[u].size() == 0) {
            for(int i=1;i<=m;i++) {
                dp[u][i]=i;
            }
            return;
        }
        for(int &v:adj[u]) {
            dfs(v);
        }
        int prev = 0;
        for(int i=1;i<=m;i++) {
            dp[u][i]=1;
            for(int &v:adj[u]) {
                dp[u][i]=(1ll*dp[u][i]*dp[v][i])%mod;
            }
            dp[u][i]=(dp[u][i]+prev)%mod;
            prev=dp[u][i];
        }
    };
    int ans = 1;
    for(int i=0;i<roots.size();i++) {
        dfs(roots[i]);
        ans = (1ll*ans*dp[roots[i]][m])%mod;
    }
    cout << ans << "\n";

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
