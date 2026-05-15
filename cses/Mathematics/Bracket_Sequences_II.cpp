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
    string str;
    cin >> str;
    if (n%2) {
        cout << 0 << "\n";
        return;
    }
    ll k = str.size();
    ll x = 0, y = 0,wsum = 0;
    for(auto& ch:str) {
        if (ch=='(')
            x++,wsum++;
        else
            y++,wsum--;
        if (wsum<0) {
            cout << 0 << "\n";
            return;
        }
    }
    if (n==k) {
        cout << 1 << "\n";
        return;
    }
    ll m = n/2;
    if (max(x,y)>m) {
        cout << 0 << "\n";
        return;
    }
    if (x==m) {
        cout << 1 << "\n";
        return;
    }
    ll tot = (fact[n-k]*((invfact[m-y]*invfact[n-k-(m-y)])%MOD))%MOD;
    ll wrngpaths = (fact[n-k]*((invfact[m-y+1]*invfact[n-k-(m-y+1)])%MOD))%MOD;
    cout << (tot-wrngpaths+MOD)%MOD << "\n";
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
