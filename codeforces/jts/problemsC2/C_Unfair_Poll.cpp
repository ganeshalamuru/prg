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
	ll n,m,k,x,y;
    cin >> n >> m >> k >> x >> y;
    if (k <= n*m) {
        cout << 1 << " " << ((k==n*m)?1:0) << " " << ((((x-1)*m+y)<=k)?1:0) << "\n";
        return;
    }
    if (n==1) {
        ll dvd = k / (n*m), rem = k%(n*m);
        ll maxq = dvd + ((rem!=0)?1:0), minq = dvd;
        cout << maxq << " " << minq << " " << (((rem==0) || ((y<=rem)))?maxq:minq)<<"\n";
        return;
    }
    ll temp1 = (k-n*m), temp2 = (n-1)*m, stepp = temp1/temp2, rem = temp1%temp2;
    ll maxq;
    if (n==2)
        maxq = (stepp+(rem!=0)+1)/2 + 1;
    else
        maxq = 1 + stepp + (rem!=0);
    ll minq = stepp/2 + 1;
    cout << maxq << " " << minq << " ";
    if (x==n) {
        if ((stepp+(rem!=0))%2 == 1 || (rem==0 || (n-2)*m+y>rem)) {
            cout << minq << "\n";
        } else {
            cout << minq+1 << "\n";
        }
    } else if (x>1) {
        if ((stepp + (rem!=0))%2 == 1) {
            if (rem ==0 || ((n-1-x)*m + y)<=rem)
                cout << maxq << "\n";
            else
                cout << maxq - 1 << "\n";
        } else {
            if (rem ==0 || (x-2)*m+y<=rem)
                cout << maxq << "\n";
            else
                cout << maxq-1 << "\n";
        }
    } else {
        if ((stepp+(rem!=0))%2 == 0 || (rem == 0 || (n-1-x)*m+y<=rem)) {
            cout << (stepp+(rem!=0)+1)/2 + 1 << "\n";
        } else {
            cout << minq << "\n";
        }
    }
    
    
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
