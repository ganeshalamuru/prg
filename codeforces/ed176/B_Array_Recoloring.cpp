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
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    if (k==1) {
        if (n==2) {
            cout << arr[0]+arr[1] << "\n";
            return;
        }
        int ans = INT_MIN;
        ans = max(ans, arr[0]+arr[n-1]);
        for(int i=1;i<n-1;i++) {
            ans = max(ans, arr[i]+max(arr[0],arr[n-1]));
        }
        cout << ans << "\n";
        return;
    }
    sort(arr.rbegin(), arr.rend());
    ll sum = 0;
    for(int i=0;i<k+1;i++)
        sum+=arr[i];
    cout << sum << "\n";
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
