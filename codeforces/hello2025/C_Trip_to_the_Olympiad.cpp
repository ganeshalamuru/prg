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
	int l,r;
    cin >> l >> r;
    bitset<32> bsl(l), bsr(r);
    int i=29, sum = 0;
    for(;i>=0;i--) {
        if (bsl[i]!=bsr[i])
            break;
        else if (bsr[i]==1)
            sum+=(1<<i);
    }
    int temp = sum+(1<<i);
    if (temp-2>=l) {
        cout << temp << " " << temp-1 << " " << temp-2 << "\n";
    } else {
        cout << temp+1 << " " << temp << " " << temp-1 << "\n";
    }
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
