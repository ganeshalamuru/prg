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


int mex(vector<int>&arr) {
    set<int> ss{arr.begin(), arr.end()};
    for(int i=0;i<3;i++) {
        if (ss.find(i) == ss.end())
            return i;
    }
    return 3;
}

void solve() {
	int n,x,y;
    cin >> n >> x >> y;
    x--,y--;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++) {
        adj[i].push_back((i-1+n)%n);
        adj[i].push_back((i+1)%n);
    }
    adj[x].push_back(y);
    adj[y].push_back(x);
    vector<int> ans(n,-1), vis(n,0);
    queue<int> qq;
    qq.push(0);
    vis[0]=1;
    while(!qq.empty()) {
        int v = qq.front();
        qq.pop();
        vector<int> knownvalues;
        for(int &u:adj[v]) {
            if (ans[u]!=-1) {
                knownvalues.push_back(ans[u]);
            } else if(vis[u]==0){
                qq.push(u);
            }
        }
        int mexx = mex(knownvalues);
        ans[v]=mexx;
    }
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
    cout << "\n";
    
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
