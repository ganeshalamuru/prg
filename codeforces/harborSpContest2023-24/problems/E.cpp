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



void solve(){
	ll totalturns = 0;
    map<ll,ll> freq;
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll&i:arr)
        cin >> i,freq[i]++;
    for(auto kv:freq) {
        ll numbits = 0;
        ll val = kv.first;
        while(val > 0) numbits+=(val&1), val>>=1;
        ll curTotalTurns;
        if (numbits == 0) {
            curTotalTurns = 1;
        } else if (numbits == 1) {
            curTotalTurns = 2;
        } else {
            curTotalTurns = mmul(2, numbits - 1);
            curTotalTurns = madd(curTotalTurns, 1);
        }
        curTotalTurns = mmul(curTotalTurns, mmul(kv.second, kv.second));
        totalturns = madd(totalturns, curTotalTurns);   
    }
    int m = freq.size();
    vector<vector<int>> bitvec(m,vector<int>(32,0));
    int i=0;
    for(auto kv:freq) {
        ll val = kv.first;
        int j=0;
        while(val > 0) bitvec[i][j++] = (val&1), val>>=1;
        reverse(bitvec[i].begin(), bitvec[i].end());
        i++;
    }
    for(int j=0;j<32;j++) {
        ll cnt = 0;
        for(int l=0;l<m;l++) {
            cnt+=bitvec[l][j];
        }
        totalturns = madd(totalturns, mmul(2,mmul(cnt, max(0ll,cnt-1))));
    }
    totalturns = madd(totalturns, mdiv(mmul(m, max(0,m-1)), 2));
    cout << "totalturns " << totalturns << "\n";
    ll expectedturns = mdiv(totalturns, mmul(n,n));
    cout << expectedturns << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
