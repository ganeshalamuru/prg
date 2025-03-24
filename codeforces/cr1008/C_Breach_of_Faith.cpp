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
    vector<int> b(2*n);
    set<ll> ss;
    for(int &num:b)
        cin >> num,ss.insert(num);
    sort(b.rbegin(), b.rend());
    ll psum = 0,nsum=0;
    for(int i=0;i<n;i++)
        psum+=b[i];
    for(int i=n;i<2*n;i++)
        nsum+=b[i];
    vector<ll>a(2*n+1);
    for(int i=0,j=1;i<n;i++,j+=2)
        a[j]=b[i];
    for(int i=n,j=2;i<2*n;i++,j+=2)
        a[j]=b[i];
    if (ss.find(psum-nsum)==ss.end()) {
        a[0]=psum-nsum;
    } else if (psum-nsum==b[0]) {
        for(int i=0,j=2;i<n;i++,j+=2)
            a[j]=b[i];
        for(int i=n,j=1;i<2*n;i++,j+=2)
            a[j]=b[i];
        a[0]=b[2*n-1];
        a[2*n-1]=psum-nsum+2*b[2*n-1];
    }else {
        a[0]=b[0];
        a[1]=b[0]+b[0]-(psum-nsum);
    }
    for(int i=0;i<2*n+1;i++) {
        cout << a[i] << " ";
    }
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
