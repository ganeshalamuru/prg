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

ll madd(ll a, ll b, ll mod = MOD) {
    a%=mod,b%=mod;
    return (a+b)%mod;
}
ll msub(ll a, ll b,ll mod = MOD) {
    a%=mod,b%=mod;
    return (a-b+mod)%mod;
}
ll mmul(ll a, ll b,ll mod = MOD) {
    a%=mod,b%=mod;
    return (1ll*a*b)%mod;
}

ll modexpo(ll x, ll n,ll mod=MOD) {
    if (n==0) return 1;
    if (x==0) return 0;
    ll ans = 1;
    while (n>0) {
        if (n&1) ans = mmul(ans,x,mod);
        x=mmul(x,x,mod);
        n>>=1;
    }
    return ans;
}

ll mgpsum(ll prime, ll times) {
    return mmul(msub(modexpo(prime,times+1),1),modexpo(msub(prime,1),MOD-2));
}

void solve() {
	int n;
    cin >> n;
    vector<pii> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i].F >> arr[i].S;
    }
    ll numdivisors = 1;
    for(int i=0;i<n;i++) {
        numdivisors=mmul(numdivisors,madd(arr[i].S,1));
    }
    
    ll sumofdivisors = 1;
    for(int i=0;i<n;i++)
        sumofdivisors = mmul(sumofdivisors,mgpsum(arr[i].F, arr[i].S));

    vector<ll> pnumofd(n),snumofd(n);
    pnumofd[0]=madd(arr[0].S,1,MOD-1);
    for(int i=1;i<n;i++) {
        pnumofd[i]=mmul(pnumofd[i-1],madd(arr[i].S,1,MOD-1),MOD-1);
    }
    snumofd[n-1] = madd(arr[n-1].S,1,MOD-1);
    for(int i=n-2;i>=0;i--) {
        snumofd[i]=mmul(snumofd[i+1],madd(arr[i].S,1,MOD-1),MOD-1);
    }

    ll productofdivisors = 1;
    for(int i=0;i<n;i++) {
        ll tmp = (1ll*(arr[i].S)*(arr[i].S+1))/2,tmp2=1;
        if (i-1>=0)
            tmp2 = mmul(tmp2,pnumofd[i-1],MOD-1);
        if (i+1<n)
            tmp2 = mmul(tmp2,snumofd[i+1],MOD-1);
        productofdivisors=mmul(productofdivisors,modexpo(arr[i].F,mmul(tmp,tmp2,MOD-1)));
    }
    cout << numdivisors << " " << sumofdivisors << " " << productofdivisors << "\n";

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
