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

ll msub(ll a, ll b) {
    a = a%mod, b = b%mod;
    return (a-b+mod)%mod;
}

ll madd(ll a, ll b) {
    a = a%mod, b = b%mod;
    return (a+b)%mod;
}

ll mmul(ll a, ll b) {
    a = a%mod, b = b%mod;
    return (1ll * a * b)%mod;
}

void solve(){
	int n,k;
    cin >> n >> k;
    if (k>n) {
        cout << 0 << "\n";
        return;
    }
    vector<vector<int>> choose(n+1,vector<int>(k+1,0));
    for(int i=0;i<=n;i++)
        choose[i][0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=min(i,k);j++) {
            choose[i][j] = madd(choose[i-1][j], choose[i-1][j-1]);
        }
    }
    int ans = 0;
    for(int i=0;i<k;i++) {
        int numways = mmul(choose[k][i], mmul(k-i, powe(k-i-1, n-1)));
        if (i%2==0)
            ans = madd(ans, numways);
        else
            ans = msub(ans, numways);
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
