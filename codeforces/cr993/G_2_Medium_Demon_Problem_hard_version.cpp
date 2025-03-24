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




void solve() {
	int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        adj[arr[i]].push_back(i);
    }
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++) {
        if (vis[i]==1)
            continue;
        int j=i;
        // fill currently visting with -1
        while(vis[j]==0)
            vis[j]=-1,j=arr[j];
        //fill cycle with 2
        while(vis[j]==-1)
            vis[j]=2,j=arr[j];
        j=i;
        // fill the tail with 1
        while(vis[j]==-1)
            vis[j]=1,j=arr[j];

    }
    int ans = INT_MIN;
    for(int i=1;i<=n;i++) {
        if (vis[i]!=2)
            continue;
        int j=i;
        while(vis[j]==2) {
            vis[j]=3;
            stack<int> stk;
            for(int &v:adj[j]) {
                if (vis[v]==2 || vis[v]==3)
                    continue;
                int sum = 0;
                stk=stack<int>{};
                stk.push(v);
                while (!stk.empty()) {
                    int tt = stk.top();
                    sum++;
                    stk.pop();
                    for(int &to:adj[tt]) {
                        if (vis[to]==2 || vis[to]==3)
                            continue;
                        stk.push(to);
                    }
                }
                ans = max(ans, sum);
            }
            j=arr[j];
        }
    }
    if (ans==INT_MIN)
        cout << 2 << "\n";
    else
        cout << ans+2 << "\n";
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
