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
    int k;
    cin >> k;
	string s,t;
    cin >> s >> t;
    if (abs((int)s.size()-(int)t.size())>1){
        cout << "No\n";
    } else if (s.size()==t.size()) {
        int diff = 0;
        for(int i=0;i<s.size();i++) {
            diff+=s[i]!=t[i];
        }
        if (diff>1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    } else {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++)
            freq[s[i]-'a']++;
        for(int j=0;j<t.size();j++)
            freq[t[j]-'a']--;
        int nz = 0;
        for(int i=0;i<26;i++) {
            nz+=freq[i]!=0;
        }
        if (nz>1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}




signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
