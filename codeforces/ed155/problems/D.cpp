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

int madd (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a + b)%mod;
}
int mmul (ll a, ll b){
    a = a%mod, b = b%mod;
	return (1ll * a * b)%mod;
}

void solve(){
	int n;
    cin >> n;
    vector<vector<int>>arr(31,vector<int>(n+1,0));
    for(int i=1,j,x;i<=n;i++) {
        cin >> x;
        j=0;
        while(x>0) {
            if (x&1)
                arr[j][i]=1;
            x>>=1,j++;
        }
    }
    vector<int>prefix(n+1,0);
    vector<vector<int>>cnt(n+1,vector<int>(2,0));
    cnt[0][0]=1;
    int ans = 0;
    for(int i=0;i<31;i++) {
        ll lensum[2]={n+1,0};
        for(int j=1;j<=n;j++) {
            prefix[j] = prefix[j-1]^arr[i][j];
            cnt[j][prefix[j]] = cnt[j-1][prefix[j]] + 1;
            cnt[j][prefix[j]^1] = cnt[j-1][prefix[j]^1];
            lensum[prefix[j]] += n-j+1;
        }
        ll total = 0;
        for(int j=n;j>=1;j--) {
            lensum[0] -= cnt[j][0];
            lensum[1] -= cnt[j][1];
            total+=lensum[prefix[j]^1];
        }
        ans = madd(ans, mmul(total, (1<<i)));
    }
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
