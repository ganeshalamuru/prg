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

int madd (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a + b)%mod;
}
int msub (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a - b + mod)%mod;
}
int mmul (ll a, ll b){
    a = a%mod, b = b%mod;
	return (1ll * a * b)%mod;
}
int minv (ll a){
    a = a%mod;
	return powe(a, mod-2);
}
int mdiv (ll a, ll b){
	return mmul(a, minv(b));
}

int fac[M];

int ncr(int n, int r){
    if (r < 0 || n < 0 || r > n)
        return 0;
    return mdiv(fac[n], mmul(fac[r], fac[n-r]));
}

void pre(){
    fac[0] = 1;
    for (int i = 1; i < 2600; i ++){
        fac[i] = mmul(i, fac[i-1]);
    }
}

void solve(){
	int k,n;
    cin >> n >> k;
    vector<vector<int>> edges(n);
    for(int i=1,p;i<n;i++) {
        cin >> p;
        edges[p].push_back(i);
    }
    vector<int> numwaystocolor(k+1,0);
    for(int i=2;i<=k;i++)
        numwaystocolor[i] = mmul(ncr(k,i),mmul(i, powe(i-1, n-1)));
    vector<int> numwaystocolorexact(k+1,0);
    int waystocolorsum = 0;
    for(int i=2;i<=k;i++) {
        numwaystocolorexact[i] = msub(numwaystocolor[i],numwaystocolor[i-1]);
    }
    cout << msub(mmul(k,powe(k-1,n-1)), mmul(mmul(k,k-1), powe(k-2,n-1))) << "\n";
}




signed main(){
    fast;
    int t = 1;
    pre();
    while(t--){
    	solve();
    }
    return 0;
}
