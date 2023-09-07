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
	int m,k,a1,ak;
    cin >> m >> k >> a1 >> ak;

    int nk = m / k;
    int n1 = m%k;

    if (n1<=a1 && nk <= ak) {
        cout << 0 << "\n";
    } else {
        int f1 = max(0,n1 - a1), fk = max(0,nk-ak);
        if (f1 > 0) {
            cout << f1 + fk << "\n";
        } else {
            int extraOnes = a1-n1;
            int kto1 = extraOnes / k;
            if (kto1 >= nk-ak)
                cout << 0 << "\n";
            else
                cout << nk-ak-kto1 << "\n";
        }
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
