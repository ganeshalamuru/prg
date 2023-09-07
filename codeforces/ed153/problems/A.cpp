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
	string s;
    cin >> s;
    if (s.size() == 2 && s=="()") {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (s.find("((") != string::npos || s.find("))") != string::npos) {
        int sz = 2 * s.size();
        string res = "";
        while(sz > 0) res.push_back('('),res.push_back(')'),sz-=2;
        cout << res << "\n";
    } else {
        string res = "";
        int sz = 2*s.size();
        while(sz > s.size()) res.push_back('('),sz--;
        while(sz > 0) res.push_back(')'),sz--;
        cout << res << "\n";
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
