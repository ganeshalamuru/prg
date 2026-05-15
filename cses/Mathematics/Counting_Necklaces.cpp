#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;

const ll MOD = 1e9+7;

ll modpow(ll x, ll n) {
    if (n == 0)
        return 1;
    ll res = 1;
    while (n>0) {
        if (n&1)
            res = (res*x)%MOD;
        x = (x*x)%MOD;
        n>>=1;
    }
    return res;
}

void solve() {
	ll n,m;
    cin >> n >> m;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        ll g = __gcd(1ll*i,n);
        ans = (ans + modpow(m,g))%MOD;
    }
    cout << (ans*modpow(n,MOD-2))%MOD << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
