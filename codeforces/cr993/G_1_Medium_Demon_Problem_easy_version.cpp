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
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    vector<int> val(n+1,-1),vis(n+1,0);
    for(int i=1;i<=n;i++) {
        if (vis[i]==1)
            continue;
        int j=i;
        while(vis[j]==0) {
            vis[j]=1;
            j=arr[j];
        }
        while(val[j]==-1) {
            val[j]=0;
            j=arr[j];
        }
        stack<int> stk;
        j=i;
        while(val[j]==-1) {
            stk.push(j);
            j=arr[j];
        }
        while (!stk.empty()) {
            val[stk.top()] = val[j]+1;
            j=stk.top();
            stk.pop();
        }
    }
    int ans = INT_MIN;
    for(int i=1;i<=n;i++)
        ans = max(val[i],ans);
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
