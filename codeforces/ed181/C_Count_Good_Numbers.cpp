#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	ll l,r;
    cin >> l >> r;
    ll ans = r-l+1;
    ll tmp = 0;
    vector<ll>primes{2,3,5,7};
    for(ll p:primes) {
        tmp+=(r/p - ((l-1)/p));
    }
    for(int i=0;i<4;i++) {
        for(int j=i+1;j<4;j++) {
            ll val = primes[i]*primes[j];
            tmp-=(r/val-((l-1)/val));
        }
    }
    for(int i=0;i<4;i++) {
        for(int j=i+1;j<4;j++) {
            for(int z=j+1;z<4;z++) {
                ll val = primes[i]*primes[j]*primes[z];
                tmp+=(r/val-((l-1)/val));
            }
        }
    }
    ll val = primes[0]*primes[1]*primes[2]*primes[3];
    tmp-=(r/val - ((l-1)/val));
    cout << ans - tmp << "\n";


}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
