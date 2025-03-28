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


int madd(ll a, ll b) {
    a%=mod,b%=mod;
    return (a+b)%mod;
}
int msub(ll a, ll b) {
    a%=mod, b%=mod;
    return(a-b+mod)%mod;
}

void solve() {
	int n,m,d;
    cin >> n >> m >> d;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
        cin >> grid[i];
    vector<vector<int>> dp(n,vector<int>(m,0));
    vector<int> tdp(m,0);
    for(int j=0;j<m;j++)
        if (grid[n-1][j]=='X')
            tdp[j]=1;
    int sum = 0;
    for(int j=0;j<=d&&j<m;j++)
        sum+=tdp[j];
    for(int j=0;j<m;j++) {
        if (grid[n-1][j]=='X')
            dp[n-1][j]=sum;
        if (j+d+1<m)
            sum+=tdp[j+d+1];
        if (j-d>=0)
            sum-=tdp[j-d];
    }
    for(int i=n-2;i>=0;i--) {
        sum = 0;
        int dsq = sqrtl(1ll*d*d-1);
        for(int j=0;j<=dsq&&j<m;j++) {
            sum = madd(sum, dp[i+1][j]);
        }
        for(int j=0;j<m;j++) {
            if (grid[i][j]=='X')
                dp[i][j]=sum;
            if (j+dsq+1<m)
                sum=madd(sum,dp[i+1][j+1+dsq]);
            if (j-dsq>=0)
                sum=msub(sum,dp[i+1][j-dsq]);
        }
        vector<int> temp=dp[i];
        sum = 0;
        for(int j=0;j<=d&&j<m;j++) {
            sum = madd(sum, dp[i][j]);
        }
        for(int j=0;j<m;j++) {
            if (grid[i][j]=='X')
                dp[i][j]=madd(dp[i][j],msub(sum,temp[j]));
            if (j+d+1<m)
                sum = madd(sum, temp[j+d+1]);
            if (j-d>=0)
                sum=msub(sum, temp[j-d]);
        }
    }
    int ans = 0;
    for(int j=0;j<m;j++)
        if (grid[0][j]=='X')
            ans = madd(ans, dp[0][j]);
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
