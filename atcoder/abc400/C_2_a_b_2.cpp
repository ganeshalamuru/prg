#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	ll n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<61;i++) {
        ll pow2 = (1ll<<i);
        if(pow2>n ){
            break;
        }
        for(int j=1;pow2*j*j<=n;j+=2)
            ans++;
    }
    cout << ans << "\n";


}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
