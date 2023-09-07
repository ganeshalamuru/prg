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




void solve(){
    ll n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for (int &i:arr)
        cin >> i;
	vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(k+1,vector<ll>(2,0)));
    int sw  = 1;
    while(sw < n && arr[sw-1] == arr[sw]) sw++;
    for (int j=0;j<=k;j++) {
        ll diff=0;
        dp[sw][j][arr[sw]] = (j%2 == 0 && j>=diff);
        for (int i=sw-1;i>=0;i--) {
            diff = sw-i;
            dp[sw][j][arr[sw]^1] += (diff%2 == j%2) && (j>=diff);
        }
    }
    for (int i=sw+1;i<n;i++) {
        dp[i][0][arr[i]] = 1;
        for (int j=1;j<=k;j++) {
            if (arr[i]==1) {
                dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j][1];
                dp[i][j][0] = dp[i-1][j-1][0];
            } else {
                dp[i][j][0] = dp[i-1][j][1] + dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j-1][1];
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<=k;j++) {
            cout << dp[i][j][0] << ","<<dp[i][j][1] << " \n"[j==k];
        }
    }
    cout << dp[n-1][k][0] + dp[n-1][k][1] << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
