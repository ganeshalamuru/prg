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



bool check(ll n, ll w1, ll w2, ll w3) {
    if (max(w1,max(w2,w3)) <= n / 3 && min(w1,min(w2,w3)) >= 0)
        return true;
    return false;
}

void solve(){
	ll n,k,d1,d2;
    cin >> n >> k >> d1 >> d2;
    if (n%3 != 0) {
        cout << "no\n";
        return;
    }
    ll w1 = -1 ,w2 = -1,w3 = -1;
    if ((d1+d2+k)%3 == 0) {
        w2 = (d1+d2+k)/3;
        w1 = w2 - d1, w3 = w2 - d2;
        if (check(n,w1,w2,w3)) {
            cout << "yes\n";
            return;
        }
    }
    if ((2*d1+d2+k)%3 == 0) {
        w1 = (2*d1+d2+k) / 3;
        w2 = w1 - d1, w3 = w2 - d2;
        if (check(n,w1,w2,w3)) {
            cout << "yes\n";
            return;
        }
    } 
    if ((d1+2*d2+k)%3 == 0) {
        w3 = (d1+2*d2+k) / 3;
        w2 = w3-d2, w1 = w2 - d1;
        if (check(n,w1,w2,w3)) {
            cout << "yes\n";
            return;
        }
    }
    if ((k+2*d1-d2)%3 == 0) {
        w1 = (k+2*d1-d2) / 3;
        w2 = w1 - d1, w3 = d2 + w2;
        if (check(n,w1,w2,w3)) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
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
