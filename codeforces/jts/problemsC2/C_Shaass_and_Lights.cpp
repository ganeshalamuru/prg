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

ll mmul(ll a, ll b) {
    a%=mod, b%=mod;
    return(a*b)%mod;
}

vector<int> fact(int n) {
    vector<int> ft(n+1);
    ft[0] = 1;
    for(int i=1;i<=n;i++) {
        ft[i] = mmul(ft[i-1], i);
    }
    return ft;
}

void solve() {
	int n,m;
    cin >> n >> m;
    vector<int> lights(m);
    for(int i=0;i<m;i++)
        cin >> lights[i];
    sort(lights.begin(), lights.end());
    vector<int> ft = fact(n);
    int ans = ft[n-m];
    ans = mmul(ans, powe(ft[lights[0]-1], mod-2));
    for(int i=1;i<m;i++) {
        int offlights = lights[i] - lights[i-1] - 1;
        if (offlights<=0)
            continue;
        ans = mmul(ans, powe(ft[offlights], mod-2));
        ans = mmul(ans, powe(2,offlights-1));
    }
    ans = mmul(ans, powe(ft[n-lights.back()], mod-2));
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
