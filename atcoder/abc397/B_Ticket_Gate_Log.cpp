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




void solve() {
	string s;
    cin >> s;
    vector<char> reqch{'i','o'};
    int rind = 0;
    int i=0, ans = 0;
    string str = "";
    while(i<s.size()) {
        if (reqch[rind]==s[i]) {
            str.push_back(s[i]);
            i++;
            rind^=1;
        } else {
            str.push_back(reqch[rind]);
            ans++;
            rind^=1;
        }
    }
    if (str.size()%2==1)
        ans++;
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
