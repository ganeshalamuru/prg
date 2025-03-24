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
    int i=0,wcount = 0;;
    string ans = "";
    while(i<s.size()) {
        if (s[i]!='W' && s[i]!='A') {
            int j=i-wcount;
            while(j<=i)
                ans.push_back(s[j]),j++;
            i++; 
            wcount=0;
            continue;
        }
        if (s[i]=='W') {
            wcount++;
            i++;
            continue;
        }
        if (wcount==0) {
            ans.push_back('A');
            i++;
        } else {
            ans.push_back('A');
            while(wcount>0)
                ans.push_back('C'),wcount--;
            i++;
        }
    }
    if (wcount>0) {
        int j = s.size()-wcount;
        while(j<s.size())
            ans.push_back('W'),j++;
    }
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
