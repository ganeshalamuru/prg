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




void solve(){
	int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n),b(m);
    ll suma = 0;
    for(int &i:a)
        cin >> i,suma+=i;
    for(int &i:b)
        cin >> i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if (k%2 == 1) {
        cout << max(suma, suma-a[0]+b.back()) << "\n";
    } else {
        if (a[0] >= b.back()) {
            cout << suma - a.back() + b[0] << "\n";
        } else {
            cout << suma - a.back() - a[0] + min(a.back(),b.back()) + min(a[0],b[0])<< "\n";
        }
    }
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
