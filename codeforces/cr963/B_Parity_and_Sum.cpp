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
    vector<int> arr(n);
    int even = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        even += (arr[i]%2 == 0);
    }
    if (even == n || even == 0) {
        cout << 0 << "\n";
        return;
    }
    sort(arr.rbegin(), arr.rend());
    int maxoddind = 0;
    for(int i=0;i<n;i++) {
        if (arr[i]%2 == 1) {
            maxoddind = i;
            break;
        }
    }
    ll sumOfevens = 0;
    for(int j=maxoddind+1;j<n;j++) {
        if (arr[j]%2 == 0) {
            sumOfevens+=arr[j];
        }
    }
    ll maxodd = arr[maxoddind] + sumOfevens;
    int j=maxoddind-1;
    while(j>=0) {
        if (maxodd < arr[j])
            break;
        maxodd = max(maxodd, maxodd + arr[j]);
        j--;
    }
    if (j != -1)
        cout << even + 1 << "\n";
    else
        cout << even << "\n";


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
