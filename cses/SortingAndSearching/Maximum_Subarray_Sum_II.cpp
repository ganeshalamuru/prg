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
	int n,a,b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    // longest subarray sum ending at i with length 1<=len<=b-a+1
    vector<ll> dp(n,0);
    ll ssum = 0, remssum = 0;
    int diff=b-a+1;
    set<pair<ll,ll>,greater<pair<ll,ll>>> ss;
    for(int i=n-1;i>=n-diff;i--)
        ssum+=arr[i],ss.insert({ssum, i});
    for(int i=n-1;i>=0;i--) {
        while(!ss.empty() && ss.begin()->S>i)
            ss.erase(ss.begin());
        dp[i]=ss.begin()->F-remssum;
        if(i-diff>=0) {
            ssum+=arr[i-diff];
            ss.insert({ssum,i-diff});
        }
        remssum+=arr[i];
    }
    ll ans = LLONG_MIN;
    ssum=0;
    for(int j=1,i=n-1;j<a;j++,i--)
        ssum+=arr[i];
    for(int i=n-1;i>=a-1;i--) {
        ans = max(ans, dp[i-a+1]+ssum);
        ssum-=arr[i];
        ssum+=arr[i-a+1];
    }
    cout << ans << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
