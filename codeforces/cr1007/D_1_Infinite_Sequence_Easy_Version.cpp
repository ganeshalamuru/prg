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
	ll n,l,r;
    cin >> n >> l >> r;
    vector<int> arr(n+1);
    for(int i=0;i<n;i++)
        cin >> arr[i+1];
    if (l<=n) {
        cout << arr[l] << "\n";
        return; 
    }
    vector<int> pxor(n+1,0);
    for(int i=1;i<=n;i++)
        pxor[i]=pxor[i-1]^arr[i];
    if (n%2==0) {
        arr.push_back(pxor[n/2]);
        pxor.push_back(pxor.back()^arr.back());
        n++;
    } 
    int ans = 0;
    l/=2;
    while(l>0) {
        if (l<=n || l%2==1) {
            ans^=pxor[min(n,l)];
            break;
        }
        ans^=pxor[n];
        l/=2;
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
