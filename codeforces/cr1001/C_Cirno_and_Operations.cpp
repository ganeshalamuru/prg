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
    ll sum = 0;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i],sum+=arr[i];
    if (n==1) {
        cout << arr[0] << "\n";
        return;
    }
    vector<ll> a = arr;
    ll ans = sum;
    for(int i=1;i<n;i++) {
        vector<ll> temp;
        for(int j=1;j<a.size();j++)
            temp.push_back(a[j]-a[j-1]);
        a=temp;
        sum = accumulate(a.begin(), a.end(), 0ll);
        ans = max(ans, max(sum,-sum));
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
