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
	int x;
    cin >> x;
    vector<int>a;
    a.push_back(x);
    int powtwos;
    
    while(true) {
        powtwos=1;
        int y = a.back();
        while(!(y&1)) y = y>>1, powtwos*=2;
        if(a.back()==powtwos)
            break;
        a.push_back(a.back()-powtwos);
    }
    while(a.back() != 1) {
        a.push_back(a.back()-(powtwos>>1));
        powtwos = powtwos>>1;
    }

    cout << a.size() << "\n";
    for(int i:a)
        cout << i << " ";
    cout << "\n";

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
