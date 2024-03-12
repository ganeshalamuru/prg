#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 998244353, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

int madd (int a, int b){
    a = a%mod, b = b%mod;
	return (0ll + a + b)%mod;
}


vector<vector<vector<int>>> dp(1e5,vector<vector<int>>(3,vector<int>(200,0)));


void solve(){
	int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i],arr[i]--;
    if (arr[0] != -2) {
        dp[0][2][arr[0]] = 1;
    } else {
        for(int j=0;j<200;j++)
            dp[0][2][j] = 1;
    }
    for(int i=1;i<n;i++) {
        int prefix = 0;
        int suffix = 0;
        for(int j=0;j<200;j++) {
            if (arr[i] != -2) {
                if (arr[i]==j) {
                    dp[i][0][j] = madd(dp[i-1][0][j], madd(dp[i-1][1][j], dp[i-1][2][j]));
                    dp[i][2][j] = prefix;
                }
                if (arr[i]==199-j) {
                    dp[i][1][199-j] = suffix;
                }
            } else {
                dp[i][0][j] = madd(dp[i-1][0][j], madd(dp[i-1][1][j], dp[i-1][2][j]));
                dp[i][1][199-j] = suffix;
                dp[i][2][j] = prefix;
            }
            prefix = madd(prefix, madd(dp[i-1][0][j], madd(dp[i-1][1][j], dp[i-1][2][j])));
            suffix = madd(suffix, madd(dp[i-1][0][199-j], dp[i-1][1][199-j]));
        }
    }
    int total = 0;
    for(int j=0;j<200;j++)
        total = madd(total, madd(dp[n-1][0][j], dp[n-1][1][j]));
    cout << total << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
