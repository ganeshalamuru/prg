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



int madd(int a, int b) {
    return(a+b)%mod;
}

void solve() {
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int> dp(n,0);
    dp[0] = (arr[0]==0);
    for(int i=1;i<n;i++) {
        // if ith student is honest
        if (arr[i-1]==arr[i])
            dp[i]=madd(dp[i], dp[i-1]);
        if (i-2<0 && arr[i]==1)
            dp[i]=madd(dp[i], 1);
        else if (i-2>=0 && arr[i-2]+1==arr[i])
            dp[i]=madd(dp[i], dp[i-2]);
    }
    if (n>=2)
        cout << madd(dp[n-1], dp[n-2]) << "\n";
    else
        cout << madd(dp[0],1) << "\n";
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
