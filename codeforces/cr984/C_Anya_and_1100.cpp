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

bool check(string &s, int i, int n) {
    if (i<n && s[i]=='1' && i+1<n && s[i+1]=='1'
            && i+2<n && s[i+2]=='0' && i+3<n && s[i+3]=='0')
        return true;
    return false;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    set<int> ss;
    for(int i=0;i<n-3;i++) {
        if (s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0')
            ss.insert(i);
    }
    int q;
    cin >> q;
    while(q--) {
        int i,v;
        cin >> i >> v;
        i--;
        char prev = s[i];
        s[i]='0'+v;
        if (prev=='0' && s[i]=='1') {
            ss.erase(i-3),ss.erase(i-2);
            if (check(s,i-1,n))
                ss.insert(i-1);
            else if (check(s,i,n))
                ss.insert(i);
        } else if (prev=='1' && s[i]=='0'){
            ss.erase(i-1), ss.erase(i);
            if (check(s,i-3,n))
                ss.insert(i-3);
            else if (check(s,i-2,n))
                ss.insert(i-2);
        }
        if (ss.size() > 0)
            cout << "YES\n";
        else
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
