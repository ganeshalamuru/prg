#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 998244353, N = 2e6+7, M = 2e5+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

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
vector<int> fac(2e5+1);
void pre(){
    fac[0] = 1;
    for (int i = 1; i < 2e5 + 1; i ++){
        fac[i] = mmul(i, fac[i-1]);
    }
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int,int>>freq;
    int i=0;
    while(i<n) {
        char ch = s[i];
        int cnt =0;
        while(i<n && ch == s[i]) cnt++, i++;
        freq.push_back({ch-'0', cnt});
    }
    int minmoves = 0;
    int totalways = 1;
    for(int j=0;j<freq.size();j++) {
        minmoves += freq[j].second-1;
        totalways = mmul(totalways, freq[j].second);
    }
    cout << minmoves << " " << mmul(fac[minmoves], totalways) << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    pre();
    while(t--){
    	solve();
    }
    return 0;
}
