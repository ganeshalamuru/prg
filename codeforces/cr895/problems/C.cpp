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


vector<int> spf(10000007);
void sieve (int n) {
    spf[1] = 1;
    for (int i = 2; i < n; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < n; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < n; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < n; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void solve(){
	int l,r;
    cin >> l >> r;
    if (l==1) l++;
    for(int z=l;z<=r;z++) {
        if (spf[z]==z)
            continue;
        int tmp = z / spf[z];
        cout << spf[z] << " " << spf[z]*(tmp-1) << "\n";
        return;
    }
    cout << -1 << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    sieve(10000001);
    while(t--){
    	solve();
    }
    return 0;
}
