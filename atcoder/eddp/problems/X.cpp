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


vector<vector<int>> dp(1e3+1, vector<int>(1e4+2,-1));

void solve(){
	int n;
    cin >> n;
    vector<int> w(n),s(n),v(n);
    for(int i=0;i<n;i++)
        cin >> w[i] >> s[i] >> v[i];
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=1e4;j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (dp[i-1][j] != -1 && s[i-1]>=j)
                dp[i][min(10001, j+w[i-1])] = max(dp[i][min(10001, j+w[i-1])], dp[i-1][j] + v[i-1]);
        }
    }
    int maxval = INT_MIN;
    for(int j=0;j<=1e4+1;j++)
        maxval = max(maxval, dp[n][j]);
    cout << maxval << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
