#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 998244353, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

ll mmul(ll a, ll b) {
    a%=mod, b%=mod;
    return (a*b)%mod;
}

ll madd(ll a, ll b) {
    a%=mod, b%=mod;
    return(a+b)%mod;
}


vector<int> mfactorial(int n) {
    vector<int> fact(n+1,0);
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i] = mmul(i,fact[i-1]);
    return fact;
}


void solve() {
	int a,b,c;
    cin >> a >> b >> c;
    int n = max(a,max(b,c));
    vector<int> fact = mfactorial(n);
    vector<vector<int>> nCr(n+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++) {
        nCr[i][0]=1;
        for(int j=1;j<=i;j++) {
            nCr[i][j] = madd(nCr[i-1][j-1], nCr[i-1][j]);
        }
    }
    int ab=0, bc=0, ca=0;
    for(int i=0;i<=max(a,b);i++) {
        ab = madd(ab, mmul(mmul(nCr[a][i], nCr[b][i]), fact[i]));
    }
    for(int i=0;i<=max(b,c);i++) {
        bc = madd(bc, mmul(mmul(nCr[b][i], nCr[c][i]), fact[i]));
    }
    for(int i=0;i<=max(c,a);i++) {
        ca = madd(ca, mmul(mmul(nCr[c][i], nCr[a][i]), fact[i]));
    }
    cout << mmul(ab,mmul(bc,ca)) << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
