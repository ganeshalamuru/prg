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



// another clean solution is to encode score1 - score2 as dp
// https://codeforces.com/blog/entry/70018
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(3,vector<ll>(2,0)));
    for(int i=0;i<n;i++)
        cin >> arr[i];
    if (n==1) {
        cout << arr[0] << "\n";
        return;
    }
    for(int i=0;i<n;i++)
        dp[i][0][0]=arr[i];
    for(int i=0;i<n-1;i++) {
        dp[i][1][0]=max(arr[i],arr[i+1]);
        dp[i][1][1]=min(arr[i],arr[i+1]);
    }
    for(int l=3;l<=n;l++) {
        for(int i=0;i<=n-l;i++) {
            dp[i][2][0]=max(arr[i]+dp[i+1][1][1],arr[i+l-1]+dp[i][1][1]);
            if (dp[i][2][0]==arr[i]+dp[i+1][1][1]) {
                dp[i][2][1]=max(arr[i+1]+dp[i+2][0][1], arr[i+l-1]+dp[i+1][0][1]);
            } else {
                dp[i][2][1]=max(arr[i]+dp[i+1][0][1], arr[i+l-2]+dp[i][0][1]);
            }
        }
        for(int z=0;z<n;z++)
            dp[z][0]=dp[z][1],dp[z][1]=dp[z][2];
    }
    cout << dp[0][1][0] << "\n";
}





signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
