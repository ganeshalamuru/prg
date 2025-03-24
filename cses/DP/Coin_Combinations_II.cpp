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



// x = {{(c2,f),(c2,f)},{c3,c4}}
// {(c1,f1),(c2,f)}
// dp[x][c] = dp[x-cmax][c] + dp[x][c-1] ...  
void solve() {
	int n,x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i=0;i<n;i++)
        cin >> c[i];
    sort(c.begin(), c.end());// is it necessary ? 
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++) { 
        for(int j=c[i];j<=x;j++) {
            dp[j]=(dp[j-c[i]]+dp[j])%mod;
        }
    }
    cout << dp[x] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
