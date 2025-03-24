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

bool isdiv(int num, int ind, string &s) {
    if (ind >= s.size()) {
        if (num!=0 && num%33 == 0) {
            return true;
        } else {
            return false;
        }
    }
    bool pos = isdiv(num*10 + (s[ind]-'0'), ind+1,s);
    if (s[ind] == '3' && ind+1<s.size() && s[ind+1]=='3') {
        pos |= isdiv(num,ind+2,s);
    }
    return pos;
} 

void solve() {
	int x;
    cin >> x;
    if (x < 33) {
        cout << "NO\n";
        return;
    }
    if (x%33 == 0 ){
        cout << "YES\n";
        return;
    }
    string str = to_string(x);
    int num=0;
    if (isdiv(num,0,str)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
