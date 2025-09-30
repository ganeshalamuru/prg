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
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    auto cmp = [](const auto &a, const auto &b){return a[1]<b[1];};
    sort(arr.begin(),arr.end(),cmp);
    vector<ll> dp(n,0);
    dp[0]=arr[0][2];
    // 
    for(int i=1;i<n;i++) {
        auto itr = lower_bound(arr.begin(), arr.end(), arr[i][0], [](const auto &a, const auto &b){return a[1]<b;});
        if (itr!=arr.begin()) {
            itr--;
            int ind = distance(arr.begin(), itr);
            dp[i]=max(dp[i-1],dp[ind]+arr[i][2]);
        } else {
            dp[i]=max(dp[i-1],1ll*arr[i][2]);
        }
    }
    cout << dp[n-1] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
