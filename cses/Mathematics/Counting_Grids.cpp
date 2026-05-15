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
    if (n==0) {
        return 1;
    }
    ll res = 1;
    while (n>0) {
        if (n&1)
            res = (res*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return res;
}


void solve() {
	ll n;
    cin >> n;
    if (n==1) {
        cout << 2 << "\n";
        return;
    }
    if (n%2 == 0) {
        cout << (modpow(2,n*n-2)+(modpow(2,(n*n)/4 - 1)+modpow(2,(n*n)/2 - 2))%MOD)%MOD;
    } else {
        cout << (modpow(2,n*n-2)+(modpow(2,(n*n+3)/4 - 1)+modpow(2,(n*n+1)/2 - 2))%MOD)%MOD;
    }


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
