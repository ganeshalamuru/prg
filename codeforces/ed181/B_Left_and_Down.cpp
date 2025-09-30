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
	ll a,b,k;
    cin >> a >> b >> k;
    ll gcdd = __gcd(a,b);
    ll ta = a/gcdd,tb=b/gcdd;
    if (ta<=k && tb<=k) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }


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
