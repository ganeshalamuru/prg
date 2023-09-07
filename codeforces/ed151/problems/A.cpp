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




void solve(){
	int x,k,n;
    cin >> n >> k >> x;
    if (x!=1) {
        cout << "YES\n";
        cout << n << "\n";
        while(n--) cout << 1 << " \n"[n==0];
    } else if (n==1 || (n%2==1 && k < 3) || (n%2==0 && k < 2)) {
        cout <<  "NO\n";
    } else {
        cout << "YES\n";
        cout << n/2 << "\n";
        int numTwos = n/2;
        if (n%2 == 1)
            numTwos--;
        while(numTwos--) cout << "2 ";
        if (n%2==1)
            cout << "3";
        cout << "\n";
    }
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
