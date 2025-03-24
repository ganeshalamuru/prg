#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 998244353, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


int madd(ll a, ll b) {
    a%=mod,b%mod;
    return(a+b)%mod;
}

int msub(ll a,ll b){
    a%=mod,b%=mod;
    return(a-b+mod)%mod;
}


void dfs(int u, int d, vector<vector<int>>&adj, vector<vector<int>>&leafs) {
    if (adj[u].size() == 0) {
        leafs[d].push_back(u);
        return;
    }
    for(int &v:adj[u])
        dfs(v,d+1,adj,leafs);
}

void solve() {
	int n;
    cin >> n;
    vector<int>p(n,-1);
    vector<vector<int>>adj(n);
    for(int i=1;i<n;i++) {
        int v;
        cin >> v;
        v--;
        p[i]=v;
        adj[v].push_back(i);
    }
    vector<vector<int>> leafs(n);
    dfs(0,0,adj,leafs);
    int d=n-1;
    while(leafs[d].size()==0)
        d--;
    vector<int> dp(n,0);
    vector<int> vis(n,0);
    int plvlsum = leafs[d].size();
    queue<int> qq;
    for(int i=0;i<leafs[d].size();i++)
        qq.push(leafs[d][i]), dp[leafs[d][i]]=1,vis[leafs[d][i]]=1;
    while(d>1) {
        int sz= qq.size();
        int curlvlsum = 0;
        while(sz--) {
            int v = qq.front();
            qq.pop();
            int pp = p[v];
            if (vis[pp]==0) {
                vis[pp]=1;
                dp[pp]=msub(madd(plvlsum,1),dp[v]);
                curlvlsum=madd(curlvlsum, dp[pp]);
                qq.push(pp);
            } else {
                dp[pp]=msub(dp[pp],dp[v]);
                curlvlsum=msub(curlvlsum,dp[v]);
            }
        }
        d--;
        for(int i=0;i<leafs[d].size();i++) {
            vis[leafs[d][i]]=1;
            qq.push(leafs[d][i]);
            dp[leafs[d][i]]=madd(plvlsum,1);
            curlvlsum=madd(curlvlsum,dp[leafs[d][i]]);
        }
        plvlsum=curlvlsum;
        
    }
    int ans = 1;
    for(int &v:adj[0])
        ans = madd(ans, dp[v]);
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
