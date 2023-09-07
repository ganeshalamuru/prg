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


int madd (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a + b)%mod;
}
int msub (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a - b + mod)%mod;
}


void solve(){
	int n;
    cin >> n;
    string s;
    cin >> s;
    s = ".."+s;
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    dp[1][1] = 1;
    vector<int> prefixsumdp(n+1,0);
    prefixsumdp[1]=1;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if (s[i]=='>')
                dp[i][j] = madd(dp[i][j], msub(prefixsumdp[i-1], prefixsumdp[j-1]));
            else
                dp[i][j] = madd(dp[i][j], prefixsumdp[j-1]);
        }
        prefixsumdp = vector<int>(n+1,0);
        prefixsumdp[1] = dp[i][1];
        for(int z=2;z<=i;z++)
            prefixsumdp[z] = madd(prefixsumdp[z-1],dp[i][z]);
    }
    int ans = 0;
    for(int j=1;j<=n;j++)
        ans = madd(ans, dp[n][j]);
    cout << ans << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
