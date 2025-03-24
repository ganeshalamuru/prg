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


bool isps(ll n) {
    ll root=roundl(sqrtl(n));
    return n == root * root;
}

void solve() {
	int n;
    cin >> n;
    if (isps((1ll*n*(n+1))/2)) {
        cout << -1 << "\n";
        return ;
    }
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++)
        ans[i]=i;
    for(int i=1;i<n;i++) {
        if (isps((1ll*i*(i+1))/2)) {
            swap(ans[i],ans[i+1]);
            i++;
        }
    }
    for(int i=1;i<=n;i++)
        cout << ans[i] << " ";
    cout << "\n";
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
