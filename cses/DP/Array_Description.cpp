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
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int> dp(m+2,0);
    if (arr[0]!=0)
        dp[arr[0]]=1;
    else
        fill(dp.begin()+1,dp.end()-1,1);
    for(int i=1;i<n;i++) {
        if (arr[i]!=0) {
            dp[arr[i]]=(dp[arr[i]]+dp[arr[i]-1])%mod;
            dp[arr[i]]=(dp[arr[i]]+dp[arr[i]+1])%mod;
            for(int j=1;j<=m;j++)
                if (j!=arr[i])
                    dp[j]=0;
        } else {
            int prevval = 0;
            for(int j=m;j>=1;j--) {
                int tmp =dp[j];
                dp[j]=((dp[j]+prevval)%mod+dp[j-1])%mod;
                prevval=tmp;
            }
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0, [](const auto &a, const auto &b){return(a+b)%mod;}) << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
