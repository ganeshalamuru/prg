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
	int n,k,l;
    cin >> n >> k >> l;
    vector<int> arr(n);
    for(int &num:arr)
        cin >> num;
    long double t=0,prevmax = 0;
    ll i=0;
    t+=arr[0];
    prevmax=0;
    i++;
    while(i<n && prevmax+k<l) {
        if (prevmax+k+t>arr[i]) {
            if (arr[i]+t>prevmax+k)
                prevmax=prevmax+k;
            else
                prevmax=arr[i]+t;
            i++;
            continue;
        } else {
            ld temp = 1.0l*(arr[i]-t-prevmax-k)/2;
            prevmax=arr[i]-t-temp;
            t+=temp;
            i++;
        }
    }
    if (prevmax+k<l)
        t+=l-prevmax-k;
    cout << (ll)(2*t) << "\n";
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
