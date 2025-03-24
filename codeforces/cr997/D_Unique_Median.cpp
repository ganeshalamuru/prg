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
	int n;
    cin >> n;
    vector<int>arr(n);
    for(int &num:arr)
        cin >> num;
    ll ans = (1ll*n*(n+1))/2;
    vector<int> psum(n+1);
    psum[0]=0;
    for(int i=1;i<10;i++) {
        for(int j=1;j<=n;j++)
            psum[j] = psum[j-1] + (arr[j-1]<=i?1:-1);
        map<int,int> mp;
        int y=0,z=1;
        while(z<=n) {
            if (arr[z-1]==i) {
                while(y<z) {
                    mp[psum[y]]++;
                    y++;
                }
            }
            ans-=mp[psum[z]];
            z++;
        }
    }
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
