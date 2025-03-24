#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+9, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


ll madd(ll a, ll b) {
    a%=mod, b%=mod;
    return (a+b)%mod;
}
ll mmul(ll a, ll b) {
    a%=mod, b%=mod;
    return (a*b)%mod;
}
ll msub(ll a, ll b) {
    a%=mod, b%=mod;
    return (a-b+mod)%mod;
}

void solve() {
	ll n,m,k,score;
    cin >> n >> m >> k;
    if (m <= (k-1)*(n/k) + n%k) {
        score = m;
    } else {
        ll numconsec = m - ((k-1)*(n/k) + n%k);
        score = mmul(msub(powe(2,numconsec+1), 2),k);
        score = (score + (m - numconsec*k))%mod;
    }
    cout << score << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
