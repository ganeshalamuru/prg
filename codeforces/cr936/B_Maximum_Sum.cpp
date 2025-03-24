#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
const int MOD = mod;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

int makeposrem(int a) {
    return (a+MOD)%MOD;
}
int madd (int a, int b){
	return (makeposrem(a)+makeposrem(b))%MOD;
}


void solve() {
	int n,k;
    cin >> n >> k;
    vector<int> arr(n),dpmod(n);
    vector<long long>dp(n);
    int modsum = 0;
    for(int &num:arr)
        cin >> num,modsum = madd(modsum, num);
    dp[0] = arr[0];
    dpmod[0] = makeposrem(arr[0]);
    for(int i=1;i<n;i++) {
        if (arr[i] >= arr[i] + dp[i-1]) {
            dp[i] = arr[i];
            dpmod[i] = makeposrem(arr[i]);
        } else {
            dp[i] = arr[i] + dp[i-1];
            dpmod[i] = madd(arr[i], dpmod[i-1]);
        }
    }
    int maxsummod = 0;
    ll maxsum = 0;
    for(int i=0;i<n;i++)
        if (maxsum < dp[i]) {
            maxsum = dp[i];
            maxsummod = dpmod[i];
        }
    int ans = modsum;
    while(k--) {
        ans = madd(ans, maxsummod);
        maxsummod = madd(maxsummod, maxsummod);
    }
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
