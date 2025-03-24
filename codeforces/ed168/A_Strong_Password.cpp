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


int timee(string s) {
    int tt = 2;
    for(int i=1;i<s.size();i++) {
        if (s[i]==s[i-1])
            tt++;
        else
            tt+=2;
    }
    return tt;
}


void solve() {
	string s;
    cin >> s;
    int ans = timee(s);
    string strpass=s;
    for(int i=0;i<26;i++) {
        char ch = 'a'+i;
        for(int j=0;j<s.size();j++) {
            string tmp = s.substr(0,j)+ch+s.substr(j);
            int tim = timee(tmp);
            if (ans < tim)
                ans = tim, strpass=tmp; 
        }
        string tmp = s+ch;
        int tim = timee(tmp);
        if (ans<tim)
            ans=tim,strpass=tmp;
    }
    cout << strpass << "\n";
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
