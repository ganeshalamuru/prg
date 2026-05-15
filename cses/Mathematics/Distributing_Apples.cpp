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
ll M = 2e6+1;
vector<ll> fact(M),invfact(M);


ll pow(ll x, ll n) {
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
    fact[0]=1;
    for(int i=1;i<M;i++) {
        fact[i]=(1ll*fact[i-1]*i)%MOD;
    }
    for(int i=0;i<M;i++) {
        invfact[i]=pow(fact[i],MOD-2);
    }
}



void solve() {
	ll n,m;
    cin >> n >> m;
    ll ans = fact[m+n-1];
    ans=(ans*((invfact[m]*invfact[n-1])%MOD))%MOD;
    cout << ans << "\n";


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
