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
	int n,a,b;
    cin >> n >> a >> b;
    if (n==1) {
        cout << 1 << "\n";
        return;
    }
    if (b==0 && a > n-2) {
        cout << -1 << "\n";
        return;
    }
    vector<int>arr(n);
    arr[0] = 1;
    int i=1,psum = 1;
    while(b--) {
        arr[i] = psum + 1;
        psum += arr[i];
        i++;
    }
    if (i==1) {
        arr[i] = arr[i-1];
        i++;
    }
    while(a--) {
        arr[i] = arr[i-1] + 1;
        i++;
    }
    while(i<n) {
        arr[i] = arr[i-1];
        i++;
    }
    for(auto num:arr)
        cout << num << " ";
    cout << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
