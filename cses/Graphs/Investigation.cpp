#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const int mod =1e9l+7;

void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n+1),radj(n+1);
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        radj[b].push_back({a,c});
    }
    vector<ll>dis(n+1,LLONG_MAX);
    set<pair<ll,ll>> ss;
    dis[n]=0;
    ss.insert({0,n});
    while (!ss.empty()) {
        auto [d,u]=*ss.begin();
        ss.erase({d,u});
        for(auto &[v,c]:radj[u]) {
            if (dis[v]==LLONG_MAX) {
                dis[v]=d+c;
                ss.insert({dis[v],v});
            } else if (d+c<dis[v]) {
                ss.erase({dis[v],v});
                dis[v]=d+c;
                ss.insert({dis[v],v});
            }
        }
    }
    vector<ll> dp(n+1,0),dp2(n+1,LLONG_MAX),dp3(n+1,LLONG_MIN);
    vector<int> vis(n+1,0);
    function<void(int)> dfs=[&](int u) {
        vis[u]=1;
        for(auto &[v,c]:adj[u]) {
            if (dis[v]==LLONG_MAX || dis[u]!=dis[v]+c)
                continue;
            if (vis[v]==0)
                dfs(v);
            dp[u]=(dp[u]+dp[v])%mod;
            if (dp2[v]!=LLONG_MAX)
                dp2[u]=min(dp2[u],dp2[v]+1);
            if (dp3[v]!=LLONG_MIN)
                dp3[u]=max(dp3[u],dp3[v]+1);
        }
        if (u==n) {
            dp[u]=1,dp2[u]=dp3[u]=0;
        }
    };
    dfs(1);
    for(ll val:{dis[1],dp[1],dp2[1],dp3[1]}) {
        cout << val << " ";
    }
    cout << "\n"; 

}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
