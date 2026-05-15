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

const ll mod = 1e9+7;

ll madd(ll a, ll b) {
    a%=mod,b%=mod;
    return (a+b)%mod;
}
ll mmul(ll a, ll b) {
    a%=mod,b%=mod;
    return (a*b)%mod;
}

ll msub(ll a, ll b) {
    a%=mod, b%=mod;
    return (a-b+mod)%mod;
}

constexpr ll modexpo(ll x, ll n) {
    if (n==0)
        return 1;
    if (x==0)
        return 0;
    ll ans = 1;
    while (n>0) {
        if (n&1) ans = mmul(ans,x);
        x=mmul(x,x);
        n>>=1;
    }
    return ans;
}

const ll minv2 = modexpo(2,mod-2); 

ll msumm(ll a) {
    return mmul(mmul(a,a+1),minv2);
}

void solve() {
	ll n;
    cin >> n;
    ll ceilsqrtn = 1;
    while (ceilsqrtn*ceilsqrtn<n)
        ceilsqrtn++;
    ll ans = 0;
    for(ll i=1;i<=ceilsqrtn;i++) {
        ll leftopen = n/(i+1),rightclose = n/i;
        if (rightclose<ceilsqrtn)
            break;
        leftopen = max(leftopen, ceilsqrtn-1);
        ans = madd(ans, mmul(i,msub(msumm(rightclose),msumm(leftopen))));
    }
    for(int i=1;i<ceilsqrtn;i++)
        ans = madd(ans, mmul(i,n/i));
    cout << ans << "\n";

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
