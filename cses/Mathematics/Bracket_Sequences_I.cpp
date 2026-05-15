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

const int M = 1e6+1;

vector<ll> fact(M),invfact(M);


ll modpow(ll x, ll n) {
    if (n==0)
        return 1;
    ll res = 1;
    while (n>0) {
        if (n&1)
            res = (res*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return res;
}

void fillfact() {
    fact[0] = 1;
    for(int i=1;i<M;i++) {
        fact[i]=(fact[i-1]*i)%MOD;
    }
    for(int i=0;i<M;i++) {
        invfact[i]=modpow(fact[i],MOD-2);
    }
}

void solve() {
    ll n;
    cin >> n;
    if (n%2) {
        cout << 0 << "\n";
        return;
    }
    ll temp = (fact[n]*((invfact[n/2]*invfact[n/2])%MOD))%MOD;
    cout << (modpow(n/2 + 1,MOD-2)*temp)%MOD << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    fillfact();
    while(t--) {
    	solve();
    }
    
    return 0;
}
